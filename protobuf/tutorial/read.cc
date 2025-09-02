#include <iostream>
#include "contact.pb.h"
#include <string>
#include <fstream>

void show(contact::Contacts *contacts)
{
	for(int i=0;i < contacts->contacts_size();++i)
	{
		std::cout<<"---------------Person " << i+1 << "---------------" << std::endl;
		const contact::PersonInfo &person = contacts->contacts(i);
		std::cout << "Name: " << person.name() << std::endl;
		std::cout << "Age: " << person.age() << std::endl;
		for(int j=0 ;j < person.phone_numbsers_size(); ++j)
		{
			const contact::Phone &phone = person.phone_numbsers(j);
			std::cout << "Phone" << j+1 << ": " << phone.number() << 
				"(" << phone.PhoneType_Name(phone.type()) << ")" << std::endl;
		}

		if(person.has_data() && person.data().Is<contact::Address>())
		{
			contact::Address address;
			person.data().UnpackTo(&address);
			if(address.home_address().empty() == false){
			 	std::cout << "Home-address: " << address.home_address() << std::endl;
			}
			if(address.unit_address().empty() == false){
			 	std::cout << "Home-address: " << address.unit_address() << std::endl;
			}
		}

		// if(person.has_qq()){
		// 	std::cout << "QQ: " << person.qq() << std::endl;
		// }
		// else if(person.has_wechat())
		// {
		// 	std::cout << "Wechat: " << person.wechat() << std::endl;
		// }
		switch(person.chat_way_case())
		{
			case contact::PersonInfo::ChatWayCase::kQq:
				std::cout << "QQ: " << person.qq() << std::endl;
				break;
			case contact::PersonInfo::ChatWayCase::kWechat:
				std::cout << "Wechat: " << person.wechat() << std::endl;
				break;
		}

		for(auto iter = person.remark().cbegin();iter != person.remark().cend();iter++)
		{
			std::cout << iter->first << ": " << iter->second << std::endl;
		}
	}
}

void ReadFile()
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
	show(&contacts);
    ifs.close();
	
}


int main()
{
	ReadFile();
    return 0;
}