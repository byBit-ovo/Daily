#pragma once
#include <fcntl.h>

bool SetNoBlock(int fd)
{
    int old = fcntl(fd, F_GETFL);
    if(old < 0)
    {
        return false;
    }
    fcntl(fd, F_SETFL, old | O_NONBLOCK);
    return true;
}