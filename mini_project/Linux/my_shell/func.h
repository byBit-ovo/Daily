#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
using namespace std;


const int base_size = 1024;
char Pwd[base_size];
char pwdenv[base_size+10];
int gargc = 0;
const int gargvnum = 64;
char* gargv[64];
char* genv[gargvnum];
char* filename = nullptr;

#define skip_space(pos) do{\
    while(isspace(*pos)){\
        ++pos;\
    }\
}while(0)

enum ReDir{
    NoneDir,
    OutputDir,
    InputDir,
    AppendDir
};
ReDir redir = NoneDir;
string Get_Name(){
    char* name = getenv("USER");
    return name==nullptr?"none":name;
}

string Get_Host(){
    char host[base_size];
    int ret = gethostname(host,sizeof(host));
    return ret==-1?"none":host;
}

string Get_Pwd(){
    char* cwd = getcwd(Pwd,sizeof(Pwd));
    snprintf(pwdenv,sizeof(pwdenv),"pwd=%s",Pwd);
    putenv(pwdenv);
    return cwd==nullptr?"none":pwdenv;
   // char* pwd = getenv("pwd");
   //return pwd==nullptr?"none":pwd;
}

void PrintCommandLine(){
    string name = Get_Name();
    string host = Get_Host();
    string pwd = Get_Pwd();
    int pos = pwd.rfind('/');
    pwd = pwd.substr(pos);
    printf("[%s@%s %s]: ",name.c_str(),host.c_str(),pwd.c_str());
    fflush(stdout);
}

bool Get_Command_Line(char* buffer){
    char* ret = fgets(buffer,base_size,stdin);
    if(ret==nullptr) return false;
    buffer[strlen(buffer)-1]='\0';
    return true;
}
void  check_dir(){
    for(int i=0;i<gargc;++i){
        if(strcmp(gargv[i],">")==0){
            if(i+1<gargc){
                filename = gargv[i+1];
            }
            gargc = i;
            gargv[i]=nullptr;
            redir = OutputDir;
        }
        else if(strcmp(gargv[i],">>")==0){

            if(i+1<gargc){
                filename = gargv[i+1];
            }
            gargc = i;
            gargv[i]=nullptr;
            redir = AppendDir;
        }
        else if(strcmp(gargv[i],"<")==0){

            if(i+1<gargc){
                filename = gargv[i+1];
            }
            gargc = i;
            gargv[i]=nullptr;
            redir = InputDir;
        }
    }
}
void Parse_Command(char* command){
    const char* sep  = " ";
    gargc = 0;
    filename = nullptr;
    redir = NoneDir;
    gargv[gargc++] = strtok(command,sep);
    while(gargv[gargc++] = strtok(nullptr,sep));
    --gargc;
    check_dir();
}

void Do_ReDir(){
    if(redir==OutputDir){
        int fd = open(filename,O_CREAT | O_TRUNC | O_WRONLY,0666);
        if(fd<0) exit(1);
        dup2(fd,1);
    }
    else if(redir==InputDir){
        int fd = open(filename,O_RDONLY,0666);
        if(fd<0) exit(1);
        dup2(fd,0);
    }
    else if(redir==AppendDir){
        int fd = open(filename,O_CREAT | O_APPEND | O_WRONLY,0666);
        if(fd<0) exit(1);
        dup2(fd,1);
    }
}
void Execute_Command(){
    pid_t id = fork();
    if(id==0){
        Do_ReDir();
        int error_num = execvpe(gargv[0],gargv,genv);
    }
    else if(id>0){
        int status = 0;
        pid_t rid = waitpid(id,&status,0);
    }
    
}

void Add_Env(){
    int i=0;
    while(genv[i]){
        ++i;
    }
    genv[i] = new char[strlen(gargv[1])*2];
    strcpy(genv[i++],gargv[1]);
    genv[i]=nullptr;

}
//shell执行内建命令
bool Check_Built_Command(){
    if(strcmp(gargv[0],"cd")==0){
        if(gargc==2){
            chdir(gargv[1]);
            return true;
        }
    }
    else if(strcmp(gargv[0],"export")==0){
            if(gargc==2){
                Add_Env();
                return true;
            }
    }
    else if(strcmp(gargv[0],"env")==0){
        for(int i=0;genv[i];++i)
            printf("%s\n",genv[i]);
        return true;
    }
    return false;
}
void Init_Env(){
    extern char** environ;
    for(int i=0;environ[i];++i){
        genv[i] = new char[strlen(environ[i])*2];
        strcpy(genv[i],environ[i]);
    }
}
