
#include "log.hpp"
// enum class sta
// {
//     DEBUG = 0
// };
// #define a b
// #define ppp std::cout << "what" << std::endl;



class test
{
public:
    test()
    {
        std::cout << "test()" << std::endl;
    }
    ~test()
    {
        std::cout << "~test()" << std::endl;
    }
    test(const test& co)
    {
        std::cout << "test(const test&)" << std::endl;
    }
};


int main()
{
    LOG(logLevel::DEBUG) << "Have a good day !";

    // ppp
    // ppp
    // int a = 3;
    // std::cout << b << std::endl;
    // std::cout << __FILE__ << std::endl;
    // std::cout << __LINE__ << std::endl;
    // std::cout << __DATE__ << std::endl;
    // std::cout << __TIME__ << std::endl;
    // std::cout << __cplusplus << std::endl;
    // std::string s(__FILE__);
    // std::cout << s << std::endl;
    // std::string arr[1] = {"DEBUG"};
    // sta a = sta::DEBUG;
    // std::cout << arr[(int)a] << std::endl;
    // printf("%05d", 3);
    // char buffer[1024];
    // buffer[0] = buffer[1] = '1';
    // printf("%s\n", buffer);
    // std::string str(buffer);
    // std::cout << str << std::endl;
    // ::printf("%s\n", str.c_str());
    // std::ofstream ofs("./log.txt", std::ios::app);
    // ofs << "666" << std::endl;
    // ofs.close();

    return 0;
}