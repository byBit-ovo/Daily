#include <unistd.h>
#include <string>
#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{

    int pfd[2];
    int ret = pipe(pfd);
    pid_t id = fork();
    if (id == 0)
    {
        // child to write
        close(pfd[0]); // close the read fd
        int cnt = 0;
        while (cnt < 11)
        {
            std::string message = "\"this content is from child:\" ";
            message += std::to_string(cnt++);
            message += '\n';
            ::write(pfd[1], message.c_str(), message.size());
            ::sleep(1);
        }
        return 1;
    }
    else if (id > 0)
    {
        // father to read
        close(pfd[1]); // close the write fd
        while (true)
        {
            char buffer[1024];
            int n = read(pfd[0], buffer, 1024);
            if (n > 0)
            {
                buffer[n] = 0;
                std::cout << "read from child:" << buffer << std::endl;
                sleep(3);
            }
            else{
                std::cout << "child quit ?,me too" << std::endl;
                pid_t rid = ::waitpid(id, nullptr, 0);
                std::cout<<"child:"<<rid<<std::endl;
                break;
            }
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

// #include <unistd.h>
// #include <string>
// #include<iostream>
// int main()
// {

//     int pfd[2];
//     int ret = pipe(pfd);
//     pid_t id = fork();
//     if (id > 0)
//     {
//         // father to write
//         close(pfd[0]); // close the read fd
//         int cnt = 0;
//         while (cnt < 11)
//         {
//             std::string message = "\"this content fron baba:\" ";
//             message += std::to_string(cnt++);
//             message += '\n';
//             ::write(pfd[1], message.c_str(), message.size());
//             ::sleep(1);
//         }
//     }
//     else if (id == 0)
//     {
//         // child to read
//         close(pfd[1]); // close the write fd
//         while (true)
//         {
//             char buffer[1024];
//             int n = read(pfd[0], buffer, 1024);
//             if (n > 0)
//             {
//                 buffer[n] = 0;
//                 std::cout << "read from baba:" << buffer << std::endl;
//                 sleep(3);
//             }
//             else{
//                 std::cout << "father quit,me too,I read "<<n<<"words" << std::endl;
//                 return 2;
//             }
//         }
//     }
//     else
//     {
//         return 1;
//     }
//     return 0;
// }