#include "http_server.h"

#include "request.h"
#include "application.h"

void HTTPServer::example_http_callback_handler(Request *request) {
	//Normál

	//Lefuttatja az összes middlewaret a requesten
	//meghívja a fő kezelő fvt

	//Asznkron

	//ha sokáig tartó műveletet hajtunk végre, akkor "callback"-eket használunk

	//pl
	//db->query_async("SELECT * FROM big_table", HTTPServer::on_big_table_select_finished);
}

void HTTPServer::http_enter_callback_default(const HTTPParser &http_parser, const HttpSession::Ptr &session) {

	Request *request = RequestPool::get_request();

	request->http_parser = &http_parser;
	request->session = &session;

	std::cout << "method: " << http_method_str(static_cast<http_method>(http_parser.method())) << std::endl;

	Application::handle_request(request);

	//ez is lehetne
	//example_http_callback_handler(request);
}

void HTTPServer::configure() {
}

void HTTPServer::initialize() {
	if (service)
		return;

	configure();

	service = TcpService::Create();
	service->startWorkerThread(threads);

	int p_port = port;

	listener_builder = new wrapper::HttpListenerBuilder();
	listener_builder->configureService(service);

	listener_builder->configureSocketOptions({ [](TcpSocket &socket) {
		socket.setNodelay();
	} });

	listener_builder->configureConnectionOptions({ AddSocketOption::WithMaxRecvBufferSize(1024) });

	listener_builder->configureListen([p_port](wrapper::BuildListenConfig builder) {
		builder.setAddr(false, "0.0.0.0", p_port);
	});

	listener_builder->configureEnterCallback([](const HttpSession::Ptr &httpSession, HttpSessionHandlers &handlers) {
		handlers.setHttpCallback(HTTPServer::http_enter_callback_default);
	});

	listener_builder->asyncRun();
}

void HTTPServer::main_loop() {
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));

		if (brynet::base::app_kbhit()) {
			break;
		}
	}
}

HTTPServer::HTTPServer() {
	port = 80;
	threads = 4;
}

HTTPServer::~HTTPServer() {
	delete listener_builder;
}
