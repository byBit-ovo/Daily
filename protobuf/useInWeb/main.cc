#include "httplib.h"


int main()
{
	httplib::Server server;
	server.Post("post/contact",[](const httplib::Request &req,httplib::Response &rsp){

	});

	server.Get("get/contact",[](const httplib::Request &req,httplib::Response &rsp){


	});

	server.listen("0.0.0.0", 9000);
	return 0;
}
