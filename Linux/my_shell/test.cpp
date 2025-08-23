#include "func.h"

int main(){
    Init_Env();
    char command[base_size];
    while(true){
        //打印命令行
        PrintCommandLine();
        //获取用户输入的命令
        if(!Get_Command_Line(command)||strlen(command)==0)
            continue;
        //分析命令
        Parse_Command(command);
        //检查内键命令
        if(Check_Built_Command()) continue;
        //执行普通命令
        Execute_Command();
    }
    
    return 0;
}






