#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <signal.h>
#include <pthread.h>
const char* gPath = "/tmp";
const int id = 1234;
#define RC1 1
#define SD1 3
#define defalutSize 1024
void signalHandler(int signum){
    std::cout << "Signal " << signum << " received" << std::endl;
    exit(0);
}
struct mmsgbuf{
    long mtype;
    char mtext[defalutSize];
    mmsgbuf(long type,const char* text){
        mtype = type;
        memset(mtext,0,defalutSize);
        memcpy(mtext,text,strlen(text));
    }
};
class Msg {
    public:
    Msg(int flag){
        int key = ftok(gPath,id);
        if(key == -1){
            std::cerr << "Error: ftok failed" << std::endl;
            exit(1);
        }
        int msgid = msgget(key,flag);
        if(msgid == -1){
            std::cerr << "Error: msgget failed" << std::endl;
            exit(2);
        }
        _msgid = msgid;
    }
    ~Msg(){}
    void dtMsg(){
        if(msgctl(_msgid,IPC_RMID,nullptr)==-1){
            std::cerr << "Error: msgctl failed" << std::endl;
            exit(3);
        }
        std::cout << "Message queue deleted" << std::endl;
    }
    void sendMsg(long type,std::string& message){
        struct mmsgbuf msg(type,message.c_str());
        if(msgsnd(_msgid,&msg,sizeof(msg.mtext)-1,0)==-1){
            std::cerr << "Error: msgsnd failed" << std::endl;
            exit(4);
        }
    }
    void recMsg(long type,std::string& message){
        struct mmsgbuf msg(type,"");
        int n = msgrcv(_msgid,&msg,sizeof(msg.mtext)-1,type,0);
        if(n==-1){
            std::cerr << "Error: msgrcv failed" << std::endl;
            exit(5);
        }
        msg.mtext[n] = '\0';
        //std::cout<<"read "<<n<<" letters"<<std::endl;
        message = msg.mtext;
    }
    private:
    int _msgid;
};

class Server:public Msg{
    public:
    Server():Msg(IPC_CREAT|IPC_EXCL|0666){}
    ~Server(){
        dtMsg();
    }
    void send(long type,std::string& message){
        Msg::sendMsg(type,message);
    }
    void rec(long type,std::string& message){
        Msg::recMsg(type,message);
    }
};

class Client:public Msg{
    public:
    Client():Msg(IPC_CREAT){}
    ~Client(){}
    void send(long type,std::string& message){
        Msg::sendMsg(type,message);
    }
    void rec(long type,std::string& message){
        Msg::recMsg(type,message);
    }
};