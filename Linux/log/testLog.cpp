#include "logger.hpp"
Logger logger;
#define DLOG logger(LogLevel::DEBUG,__FILE__,__LINE__)
#define ILOG logger(LogLevel::INFO,__FILE__,__LINE__)
#define ELOG logger(LogLevel::ERROR,__FILE__,__LINE__)
#define FLOG logger(LogLevel::FATAL,__FILE__,__LINE__)
int main()
{
    logger.toFile("log/log.txt");
    DLOG<<"hello "<<1<<" "<<1.22;
    ILOG<<"hello "<<1<<" "<<1.22;
    ELOG<<"hello "<<1<<" "<<1.22;
    FLOG<<"hello "<<1<<" "<<1.22;
    return 0;
}