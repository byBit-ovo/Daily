
#ifndef __TESTH__
#define __TESTH__
#include <functional>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <vector>
using task_t = std::function<void()>;
const char gsep = '-';
enum
{
    OK,
    FILE_OPEN_ERROR,
};

void test1();
void test2();
void test3();

#endif
