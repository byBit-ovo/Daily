#include "httplib.h"


int main()
{
	httplib::Server server;
	server.Post("post/contact",[](const httplib::Request &req,httplib::Response &rsp){
		rsp.status=200;
	});

	server.Get("get/contact",[](const httplib::Request &req,httplib::Response &rsp){

		rsp.status=200;
	});

	server.listen("0.0.0.0", 9000);
	return 0;
}
