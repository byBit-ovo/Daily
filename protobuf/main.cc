#include <iostream>
#include "contact.pb.h"
#include <string>

enum : int
{
    PUBLISH_OK,
    SET_OK
};
class Date;
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

void TestFile()
{
    contact::Contacts;
    contact::PersonInfo person1;
    person1.set_age(20);
    person1.set_name("李白");
    contact::Phone* phone_numbers = person1.add_phone_numbsers();
}
int main()
{

    return 0;
}