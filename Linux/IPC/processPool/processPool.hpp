#pragma once
#include <iostream>
#include <unistd.h>
#include <vector>
#include <cstring>
#include <functional>
#include "task.hpp"
#include <sys/wait.h>
bool checkArg(int argc)
{
    return argc == 2;
}
class Channel
{
public:
    Channel(int id, int wfd): _id(id),_wfd(wfd) {}
    int getwfd()
    {
        return _wfd;
    }
    void Close()
    {
        ::close(_wfd);
    }
    pid_t getid()
    {
        return _id;
    }

private:
    pid_t _id;
    size_t _wfd;
};

class Pool
{
public:
    Pool(char *num)
    {
        int count = std::stoi(num);
        while (count--)
        {
            int pipefd[2];
            int ret = pipe(pipefd); // creat pipe
            if (ret != 0)
            {
                continue;
            }
            pid_t id = fork();
            if (id > 0)
            {
                ::close(pipefd[0]); // father close read to write
                _pool.emplace_back(id, pipefd[1]);
            }
            else if (id == 0)
            {
                ::close(pipefd[1]); // child close write to read
                for (auto& e : _pool)
                {
                    e.Close(); // close the write port from father to brothers
                }
                dup2(pipefd[0], 0);
                work();
            }
        }
    }
    void dispatchTask(int total)
    {
        int who = 0;
        for (int i = 0; i < total; ++i)
        {
            ::write(_pool[who++].getwfd(), &who, sizeof(who));
            who %= _pool.size();
            sleep(1);
        }
    }
    ~Pool()
    {
        for(auto e:_pool){
            e.Close();
            pid_t rid = ::waitpid(e.getid(), nullptr, 0);
            if(rid>0){
                std::cout << "child-" << rid << "quit" << std::endl;
            }
        }

        std::cout << "all children had quited ,i quit too" << std::endl;
        // way1:
        //  for (int i = _pool.size() - 1; i >= 0; --i)
        //  {
        //      _pool[i].Close();
        //      pid_t rid = ::waitpid(_pool[i].getid(), nullptr, 0);
        //      if (rid > 0)
        //      {
        //          std::cout << "child-" << rid << "quit" << std::endl;
        //      }
        //  }
    }

private:
    std::vector<Channel> _pool;
};