#include <mysql/mysql.h>
#include <iostream>

int main()
{
    MYSQL *conn = mysql_init(nullptr);
    if (!conn) {
        std::cerr << "mysql_init failed\n";
        return 1;
    }

    // 连接数据库
    if (!mysql_real_connect(conn, "localhost", "root", "2005", "helloworld", 3306, NULL, 0)) {
        std::cerr << "Connection failed: " << mysql_error(conn) << std::endl;
        return 1;
    }
    if (mysql_query(conn, "SELECT NAME,AGE FROM student")) {
        std::cerr << "Query failed: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        std::cout << "NAME: " << row[0] << ", AGE: " << row[1] << std::endl;
    }

    // 清理资源
    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}
