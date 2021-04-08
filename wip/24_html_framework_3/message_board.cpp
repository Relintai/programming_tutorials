#include "message_board.h"

#include "core/request.h"

#include "sqlite/sqlite3.h"
#include <fstream>

void MessageBoard::handle_request(Request *request) {
	std::ifstream f("msgboard.db");
	if (!f.good()) {
		create_db();
	}

	if (request->http_parser->method() == HTTP_POST) {
		handle_post(request);
	}

	request->temp_body = "<html><head></head><body>";

    sqlite3 *db;
	char *err_msg = nullptr;
	int rc;

	rc = sqlite3_open("msgboard.db", &db);

	if (rc) {
		printf("Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	}

	const char *sql = "SELECT * FROM MESSAGES;";

	rc = sqlite3_exec(db, sql, MessageBoard::data_callback, request, &err_msg);

	if (rc != SQLITE_OK) {
		printf("SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}

	sqlite3_close(db);

	request->temp_body += "<form method=\"post\" action=\"/msgb\">";
	request->temp_body += "<textarea name=\"text\" rows=\"20\" cols=\"50\"></textarea><br>";
	request->temp_body += "<input type=\"submit\" />";
	request->temp_body += "</form>";

	request->temp_body += "</body></html>";
	request->response->setBody(request->temp_body);
	request->send();
}

void MessageBoard::handle_post(Request *request) {
	std::string b = request->http_parser->getBody();

	//printf("%s\n", b.c_str());

	if (b.find("text=") != 0) {
		return;
	}

	std::string val = b.substr(5, b.size() - 5);

	std::string::size_type pos = 0;
	while ((pos = val.find("%0", pos)) != std::string::npos) {
		val = val.replace(pos, 2, "<br>");
	}

	//printf("%s\n", val.c_str());

	sqlite3 *db;
	char *err_msg = nullptr;
	int rc;

	rc = sqlite3_open("msgboard.db", &db);

	if (rc) {
		printf("Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	}

    //SQL injection! -> prepared statement
	std::string sql = "INSERT INTO MESSAGES (MESSAGE) VALUES('" + val + "');";

	rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err_msg);

	if (rc != SQLITE_OK) {
		printf("SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}

	sqlite3_close(db);
}

void MessageBoard::create_db() {
	sqlite3 *db;
	char *err_msg = nullptr;
	int rc;

	rc = sqlite3_open("msgboard.db", &db);

	if (rc) {
		printf("Can't open database: %s\n", sqlite3_errmsg(db));
		return;
	}

	const char *sql = "CREATE TABLE MESSAGES ("
					  "MESSAGE    TEXT NOT NULL);";

	rc = sqlite3_exec(db, sql, NULL, NULL, &err_msg);

	if (rc != SQLITE_OK) {
		printf("SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}

	sqlite3_close(db);
}

int MessageBoard::data_callback(void *data, int argc, char **argv, char **azColName) {
    Request *request = reinterpret_cast<Request *>(data);

    request->temp_body += "Message:<br>";
    request->temp_body += argv[0];
    request->temp_body += "<br><br><br>";

    return 0;
}