#include "server.hpp"
int main(){
    creatPipe();
    server afterUsr;
    afterUsr.openForRead();
    std::string message;
    while (afterUsr.recMessage(message) > 0){
        message.insert(0, "From Client: ");
        std::cout << message << std::endl;
    }
    afterUsr.Close();
    releasePipe();
    return 0;
}