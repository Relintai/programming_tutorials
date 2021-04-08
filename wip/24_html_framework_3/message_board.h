#ifndef MESSAGE_BOARD_H
#define MESSAGE_BOARD_H

class Request;

class MessageBoard {
public:
	static void handle_request(Request *request);
	static void handle_post(Request *request);
	static int data_callback(void *data, int argc, char **argv, char **azColName);

	static void create_db();
};

#endif
