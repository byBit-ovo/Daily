#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
const char *gName = "./helper";
const mode_t gMode = 0600;
class myPipe
{
public:
    myPipe() = default;
    void creatPipe(const char* name,const mode_t mode){
        int ret = mkfifo(name, mode);
        if(ret==-1){
            std::cerr << "mkfifo error" << std::endl;
            exit(1);
        }
        _name = name;
    }

private:
    void openHelper(int flag){
        int fd = open() 
    } 
    int _fd;
    std::string _name;
};