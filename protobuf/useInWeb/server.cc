#include "httplib.h"
#include "contact.pb.h"

int main()
{
	httplib::Server server;
	server.Post("post/contact",[](const httplib::Request &req,httplib::Response &rsp){
		contact::Add_Request request;
		contact::Add_Response response;
		bool ret = request.ParseFromString(req.body);
		if(ret==false){
			rsp.status = 404;
			response.set_ok(false);
			response.set_err_desc("deserialize fail!");
			std::string result;
			bool ret2 = response.SerializeToString(&result);
			if(ret2==false){
				return;
			}
			rsp.body = result;
			rsp.set_header("Content-Type","application/protobuf");
			return;
		}
		std::cout << "Name: " << request.name() << std::endl;
		std::cout << "Age: " << request.age() << std::endl;
		for(int j=0 ;j < request.phone_numbsers_size(); ++j)
		{
			const contact::Add_Request_Phone &phone = request.phone_numbsers(j);
			std::cout << "Phone" << j+1 << ": " << phone.number() << 
				"(" << contact::Add_Request_Phone_PhoneType_Name(phone.type()) << ")" << std::endl;
		}
		response.set_ok(true);
		response.set_uuid("7nu7897fdnnfdst74b");
		std::string result;
		bool ret3 = response.SerializeToString(&result);
		if(ret3==false){
			return;
		}
		rsp.body = result;
		rsp.status=200;
		rsp.set_header("Content-Type","application/protobuf");
		return;
	});

	server.Get("get/contact",[](const httplib::Request &req,httplib::Response &rsp){

		rsp.status=200;
	});

	server.listen("0.0.0.0", 9000);
	return 0;
}
