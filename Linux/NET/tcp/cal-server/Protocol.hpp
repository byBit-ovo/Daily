#pragma once
#include <string>
#include <iostream>
#include <jsoncpp/json/json.h>

const std::string sep = "\n";

class Encrypton
{
public:
    //"38\n{json}\n89{json}\n"
    static bool Encode(std::string &message) // 解决读到的数据可能不完整的问题,在json字符串中加入报头和分隔符
    {
        if (message.empty())
            return false;
        int content_len = message.size();
        std::string package = std::to_string(content_len) + sep + message + sep;
        message = package;
        return true;
    }

    static bool Decode(std::string &package, std::string &message) // 过滤掉报头和分隔符,提取正文,得到序列化json字符串
    {
        if (package.empty())
            return false;
        int pos = package.find(sep);

        if (pos == std::string::npos) // 读的消息不完整
            return false;
        //"38\n{json}\n89{json}\n"
        std::string pre_fix = package.substr(0, pos);
        int required_lenth = pre_fix.size() + std::stoi(pre_fix) + 2 * sep.size();
        if (package.size() < required_lenth)
            return false;
        message = package.substr(pos + sep.size(), std::stoi(pre_fix));
        package.erase(0, required_lenth);
        return true;
    }
};

class Request
{
public:
    Request(int x = 0, int y = 0, char op = '+') : _x(x), _y(y), _oper(op)
    {
    }
    void Serialize(std::string &message)
    {
        Json::Value root;
        root["x"] = _x;
        root["y"] = _y;
        root["oper"] = _oper;
        Json::StreamWriterBuilder wb;
        std::unique_ptr<Json::StreamWriter> w(wb.newStreamWriter());
        std::stringstream ss;
        w->write(root, &ss);
        message = ss.str();
    }
    bool Deserialize(const std::string &message)
    {
        Json::Value root;
        Json::Reader reader;
        bool parsingSuccessful = reader.parse(message, root);
        if (!parsingSuccessful)
        {
            std::cout << "Failed to parse JSON: " << reader.getFormattedErrorMessages() << std::endl;
            return false;
        }

        _x = root["x"].asInt();
        _y = root["y"].asInt();
        _oper = root["oper"].asInt();

        return true;
    }
    int X() { return _x; }
    int Y() { return _y; }
    char OPER() { return _oper; }

private:
    int _x;
    int _y;
    char _oper;
};

class Response
{
public:
    Response() : _result(0), _code(0) {}
    Response(int result, int code) : _result(result), _code(code) {}
    bool Serialize(std::string &out_string)
    {
        Json::Value root;
        root["result"] = _result;
        root["code"] = _code;

        Json::StreamWriterBuilder wb;
        std::unique_ptr<Json::StreamWriter> w(wb.newStreamWriter());
        std::stringstream ss;
        w->write(root, &ss);
        out_string = ss.str();
        return true;
    }
    bool Deserialize(std::string &in_string)
    {
        Json::Value root;
        Json::Reader reader;
        bool parsingSuccessful = reader.parse(in_string, root);
        if (!parsingSuccessful)
        {
            std::cout << "Failed to parse JSON: " << reader.getFormattedErrorMessages() << std::endl;
            return false;
        }

        _result = root["result"].asInt();
        _code = root["code"].asInt();

        return true;
    }
    int Result() const { return _result; }
    int Code() const { return _code; }
    void SetResult(int res) { _result = res; }
    void SetCode(int c) { _code = c; }

private:
    int _result; // 结果
    int _code;   // 出错码，0,1,2,3,4
};

