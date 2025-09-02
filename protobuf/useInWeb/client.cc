#include "httplib.h"
#include "contact.pb.h"
#include "Exception.hpp"
void menu(){
	std::cout << "-----------------------------------------------------" << 
	std::endl
	<< "--------------- 请选择对通讯录的操作 ----------------" << 
	std::endl
	<< "------------------ 1、新增联系⼈ --------------------" << 
	std::endl 
	<< "------------------ 2、删除联系⼈ --------------------" << 
	std::endl
	<< "------------------ 3、查看联系⼈列表 ----------------" << 
	std::endl 
	<< "------------------ 4、查看联系⼈详细信息 ------------" << 
	std::endl
	<< "------------------ 0、退出 --------------------------" << 
	std::endl
	<< "-----------------------------------------------------" << 
	std::endl;

}
void buildReq(contact::Add_Request &req)
{

}
void addContact(httplib::Client &client)
{

	//construct req
	contact::Add_Request req;
	buildReq(req);

	//serialize to buffer
	std::string buffer;
	bool ret = req.SerializeToString(&buffer);
	if(ret == false){
		throw ContactException("Serialize fail!");
	}
	httplib::Client client("127.0.0.1",9000);

	//post to server and get response
	httplib::Result res = client.Post("post/contact",buffer,"application/protobuf");
	if(!res){
		throw ContactException(httplib::to_string(res.error()));
	}
	//deserialize to an object
	contact::Add_Response resp;
	bool ret2 = resp.ParseFromString(res->body);
	if(ret2 == false || res->status!=200)
	{
		throw ContactException("deserialize fail or response status error!");
	}
	else if(resp.ok() == false)
	{
		throw ContactException("message fail");
	}
	std::cout << "Add successfully! uuid: " << resp.uuid() << std::endl;
	
}
void deleteContact(){

}
void List(){

}
void Find(){
	
}


int main()
{
	httplib::Client client("127.0.0.1", 9000);
	int op = 0;
	enum Option: int{
		QUIT = 0,
		ADD,
		DELETE,
		LIST,
		FIND
	};
	while(true)
	{
		menu();
		std::cin >> op;
		std::cin.ignore(256,'\n');
		try
		{
			switch (op)
			{
				case QUIT: 		std::cout << "程序退出..." << std::endl; return 1;
				case ADD: 		addContact(client); break;
				case DELETE:	deleteContact();	break;
				case LIST:		List();				break;
				case FIND:		Find();				break;
				default: 		std::cout << "选择有误..." << std::endl; break;
			}
		}
		catch(const ContactException& e){
			std::cout << "throw a exception: " << e.what() << std::endl;
		}
	}
	return 0;
}
