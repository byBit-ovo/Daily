#include <iostream>
#include "contact.pb.h"
#include <string>
#include <fstream>
void test1()
{
    std::string ser_data;
    contact::PersonInfo person1;
    person1.set_name("哪吒");
    person1.set_age(20);
    bool ret = person1.SerializeToString(&ser_data);
    if (ret == false)
    {
        std::cout << "serialize fail!" << std::endl;
        return ;
    }

    std::cout << "serialized data: " << ser_data << std::endl;
    contact::PersonInfo result;
    // 将二进制序列反序列化进PersonInfo
    bool ret2 = result.ParseFromString(ser_data);
    if (ret2 == false)
    {
        std::cout << "unserialize fail!" << std::endl;
        return ;
    }
    std::cout << "Person.age: " << result.age() << std::endl
              << "Person.name: " << result.name() << std::endl;
}
void addPerson(contact::PersonInfo *person){
    int32_t age;
    std::string name;
    std::cout << "姓名：";
    std::getline(std::cin,name);
    std::cout << "年龄：";
    std::cin >> age;
    person->set_age(age);
    person->set_name(name);

    std::cin.ignore(256,'\n');

	while(1){
		std::cout << "电话：" ;
		std::string number;
		std::getline(std::cin,number);
		if(number.empty()){
			break;
		}
		std::cout << "选择电话类型(0: 移动电话， 1: 座机)";
		int type;
		std::cin >> type;
		std::cin.ignore(256,'\n');
		contact::Phone * phones = person->add_phone_numbsers();
		switch(type)
		{
			case 0: 
				phones->set_type(contact::Phone_PhoneType::Phone_PhoneType_Mobile_Phone);
				break;
			case 1: 
				phones->set_type(contact::Phone_PhoneType::Phone_PhoneType_TELEPHONE);
				break;
			default:
				std::cout << "类型有误" << std::endl;
				return;
		}
		phones->set_number(number);
	}
	
}

void WriteFile()
{
    std::ifstream ifs("contacts.txt",std::ios::in | std::ios::binary);
    if(ifs.is_open() == false){
        std::cout << "文件打开失败" << std::endl;
        return;
    }
    contact::Contacts contacts;
    bool ret = contacts.ParseFromIstream(&ifs);
    if(ret==false){
        std::cout << "反序列化失败..." << std::endl;
        ifs.close();
        return ;
    }
    addPerson(contacts.add_contacts());
	std::ofstream ofs("contacts.txt", std::ios::binary | std::ios::out);
    bool ret2 = contacts.SerializeToOstream(&ofs);
    if(ret2==false){
        std::cout << "序列化失败..." << std::endl;
        ifs.close();
        return ;
    }
    std::cout << "write successfully" << std::endl;
	
    ifs.close();
	ofs.close();
}


int main()
{
	WriteFile();
    return 0;
}