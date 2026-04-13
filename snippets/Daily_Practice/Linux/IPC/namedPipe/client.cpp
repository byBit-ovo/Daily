#include "client.hpp"
#include <cstring>
int main()
{
    Client usr;
    sleep(3);
    usr.openForWrite();
    std::string message;
    int cnt = 10;

    while (cnt--)
    {
        message = "send message " + std::to_string(cnt);
        usr.sendMessage(message);
        sleep(1);
    }
    usr.Close();
    return 0;
}