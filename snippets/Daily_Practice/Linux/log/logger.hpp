#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
//[debug][thread-id][2025年5月12日: 16:34:04][filename][line]...
void getTime(std::string *out)
{
    time_t now = time(nullptr);
    struct tm *stm = localtime(&now);
    std::stringstream ss;
    ss << stm->tm_year + 1900 << "年" << stm->tm_mon << "月" << stm->tm_mday << "日: " << stm->tm_hour << ":" << stm->tm_min << ":" << stm->tm_sec;
    *out = ss.str();
}
class LogStrategy
{
public:
    virtual void flush(const std::string &message) = 0;
};
enum class LogLevel
{
    DEBUG,
    INFO,
    ERROR,
    FATAL
};
std::string getLevelStr(LogLevel level)
{
    switch (level)
    {
    case LogLevel::DEBUG:
        return "DEBUG";
    case LogLevel::INFO:
        return "INFO";
    case LogLevel::ERROR:
        return "ERROR";
    case LogLevel::FATAL:
        return "FATAL";
    }
    return "UNKNOWN";
}
class FileLog : public LogStrategy
{
public:
    FileLog(const std::string &file) : _file_name(file) {}
    virtual void flush(const std::string &message) override
    {
        std::ofstream of(_file_name,std::ios::out | std::ios::app);
        if (of.is_open() == false)
        {
            std::cout<<"打开文件错误"<<std::endl;
            return;
        }
        of << message<<std::endl;
        of.close();
    }

private:
    std::string _file_name;
};

class NormalLog : public LogStrategy
{
public:
    virtual void flush(const std::string &message) override
    {
        std::cout << message << std::endl;
    }
};
class Logger;
//[debug][thread-id][2025年5月12日: 16:34:04][filename:line]...

class Logger
{
public:
    class LogMessage
    {
    public:
        LogMessage(LogLevel level, const std::string &filename, int line, Logger *master)
            : _master(master)
        {
            std::stringstream ss;
            std::string levelStr = getLevelStr(level);
            std::string time;
            getTime(&time);
            ss << "[" << levelStr << "]" << "[" << pthread_self() << "]" << "[" << time << "]" << "[" << filename << ":" << line << "]";
            _message = ss.str();
        }
        template <class T>
        LogMessage &operator<<(const T &info)
        {
            std::stringstream ss;
            ss << info;
            _message += ss.str();
            return *this;
        }
        ~LogMessage()
        {
            _master->flush(_message);
        }

    private:
        Logger *_master;
        std::string _message;
    };
    Logger() : _strategy(std::make_shared<NormalLog>()) {}
    LogMessage operator()(LogLevel level, const std::string &filename, int line)
    {
        return LogMessage(level, filename, line, this);
    }
    void flush(const std::string &message)
    {
        _strategy->flush(message);
    }
    void toNormal()
    {
        _strategy = std::make_shared<NormalLog>();
    }
    void toFile(const std::string &file)
    {
        _strategy = std::make_shared<FileLog>(file);
    }

private:
    std::shared_ptr<LogStrategy> _strategy;
};