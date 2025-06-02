#pragma once
#include <functional>
#include <iostream>
#include <unistd.h>
using task_t = std::function<void()>;

class taskManager
{
public:
    taskManager()
    {
        _task.emplace_back([]()
                           { std::cout << "task about mysql..." << std::endl; });
        _task.emplace_back([]()
                           { std::cout << "task about url..." << std::endl; });
        _task.emplace_back([]()
                           { std::cout << "task about parse secret..." << std::endl; });
        _task.emplace_back([]()
                           { std::cout << "task about vedio..." << std::endl; });
        _task.emplace_back([]()
                           { std::cout << "task about image..." << std::endl; });
        _task.emplace_back([]()
                           { std::cout << "task about hahahahaha..." << std::endl; });
    }

    void addTask(task_t task)
    {
        _task.emplace_back(task);
    }
    void execTask(int cho)
    {
        cho %= _task.size();
        _task[cho]();
    }
    int size()
    {
        return _task.size();
    }

private:
    std::vector<task_t> _task;
};
::taskManager task;
void work()
{
    while (true)
    {
        int cmd;
        int ret = ::read(0, &cmd, sizeof(cmd));
        if (ret == 0)
        {
            std::cout << getpid() << "this pool quit" << std::endl;
            exit(0);
        }
        task.execTask(cmd);
    }
}
