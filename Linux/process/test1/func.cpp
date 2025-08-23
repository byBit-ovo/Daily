#include "test.h"
std::vector<int> data;

int _save(){
    std::string name = std::to_string(time(nullptr));
    name += ".backup";
    FILE *fp = fopen(name.c_str(), "w");
    if(fp==nullptr){
        return FILE_OPEN_ERROR;
    }
    std::string dataStr;
    for (auto e : data) dataStr += std::to_string(e)+gsep;
    fputs(dataStr.c_str(), fp);
    fclose(fp);
    return OK;
}
void Save(){
    pid_t id = fork();
    if(id<0){
        exit(1);
    }
    if(id==0){
        int info = _save();
        exit(info);
    }
    else{
        int status = 0;
        pid_t wait_id = waitpid(id, &status,0);
        if(wait_id>0){
            int exit_code = WEXITSTATUS(status);
            if(exit_code==0){
                std::cout << "backup success!" << std::endl;
            }
            else{
                std::cout << "backup error!" << std::endl;
            }
        }
        else{
            perror("waitpid fail!\n");
        }
    }
}
void test2(){
    for (int i = 0; true;++i){
        sleep(1);
        data.push_back(i);
        if(i%10==0){
            Save();
        }
    }
}
void test1(){
        pid_t id = fork();
    if(id<0){
        std::cout << strerror(errno) << std::endl;
    }
    else if(id==0){
        int cnt = 5;
        while(cnt--){
            sleep(1);
            std::cout << "I am child process,my id:" << getpid() << std::endl;
        }
        exit(123);
    }
    else{
        int rtid = 0;
        pid_t child_id = waitpid(id,&rtid,0);
        if(WIFEXITED(rtid)){
            std::cout<<"wait sucess,child id:"<<child_id<<std::endl;
            std::cout << "no signal,exit normally" << std::endl;
            std::cout << "exit status code:" << WEXITSTATUS(rtid) << std::endl;
        }
        else{
            std::cout << "quit error,quit signal:" << WTERMSIG(rtid) << std::endl;
        }
        int cnt = 100;
        while(cnt--){
            sleep(1);
            std::cout << "I am parent,my id:" << getpid() << std::endl;
        }
    }

}
void Back_up(){
    std::cout << "backup"<<std::endl;
} 
void Read_book(){
    std::cout << "read a book" << std::endl;
}
void Write_book(){
    std::cout << "write a character" << std::endl;
}
void Login(){
    std::cout << "login" << std::endl;
}
void Load_task(std::vector<task_t>& tasks){
    tasks.push_back(Read_book);
    tasks.push_back(Write_book);
    tasks.push_back(Login);
    tasks.push_back(Back_up);
}
void test3()
{
    std::vector<task_t> tasks;
    Load_task(tasks);
    pid_t id = fork();
    if(id==0){
        while(true){
            sleep(1);
            std::cout << "I am child: " << getpid() << std::endl;
        }
    }
    else if(id>0){
        while(true){
            pid_t rid = waitpid(id, nullptr, WNOHANG);
            if(rid==0){
                for(auto &task: tasks){
                    sleep(3);
                    task();
                }
            }
            else if(rid>0){
                std::cout << "子进程正常退出" << std::endl;
                execl("./tmpp", "./tmpp",nullptr);
                break;
            }
            else{
                std::cout << "子进程异常退出" << std::endl;
                break;
            }
        }
    }
}
