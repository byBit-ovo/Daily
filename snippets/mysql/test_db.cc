#include <cstddef>
#include <mysql/plugin_auth_common.h>
#include <mysql/mysql.h>
#include <iostream>

const std::string host = "127.0.0.1";
const std::string user = "root";
const std::string pswd = "200533";
const std::string db = "IM";

int main(){
    const char* info = mysql_get_client_info();
    MYSQL* sql = mysql_init(nullptr);
    if(sql == nullptr) {
        std::cout << "MySQL init error" << std::endl;
        return 1;
    }
    std::cout << info << std::endl;
    sql = mysql_real_connect(sql, host.c_str(), user.c_str(), pswd.c_str(), db.c_str(), 3306, nullptr, 0);
    if(sql == nullptr) {
        std::cout << "MySQL connect error" << std::endl;
        return 1;
    }
    std::cout << "MySQL connect success" << std::endl;
    while(true) {
        std::string command;
        std::cout << "MySQL>>";
        std::cin >> command;
        if(command == "exit") {
            break;
        }
    }
    mysql_close(sql);
    return 0;
}