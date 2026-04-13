#include <unordered_map>
#include <vector>
#include <string>
#include "log.hpp"
#include <sstream>
#include <fstream>

const std::string Sep = "\r\n";
const std::string Space = " ";
const std::string root = "wwwroot";
const std::string home = "index.html";
const std::string miniSep = ": ";
const std::string page404 = "wwwroot/404.html";

class HttpRequest
{

public:
    HttpRequest(const std::string &req) : _req(req)
    {
    }
    ~HttpRequest() {}

    void DeserializeAndSave()
    {
        Separate_ReqLine();
        Separate_Header();
        Get_Body();
    }

    void Debug()
    {
        LOG(logLevel::DEBUG) << _method;
        LOG(logLevel::DEBUG) << _uri;
        LOG(logLevel::DEBUG) << _version;

        for (int i = 0; i < _header.size(); ++i)
        {
            LOG(logLevel::DEBUG) << _header[i];
        }

        LOG(logLevel::DEBUG) << _body;
    }
    std::string GetUri()
    {
        return _uri;
    }

private:
    bool Separate_ReqLine()
    {
        LOG(logLevel::DEBUG) << "Separate_ReqLine";
        int pos = _req.find(Sep);
        if (pos == std::string::npos)
        {
            return false;
        }
        std::string first_line = _req.substr(0, pos);
        _req.erase(0, pos + Sep.size());
        std::stringstream ss(first_line);
        ss >> _method >> _uri >> _version;
        return true;
    }

    void Separate_Header()
    {
        LOG(logLevel::DEBUG) << "Separate_Header";

        while (true)
        {
            int pos = _req.find(Sep);
            if (pos == std::string::npos)
            {
                break;
            }
            if (pos == 0)
            {
                _req.erase(0, pos + Sep.size());
                break;
            }
            _header.emplace_back(_req.substr(0, pos));
            _req.erase(0, pos + Sep.size());
        }
    }
    void Get_Body()
    {
        LOG(logLevel::DEBUG) << "Get_Body";

        _body = _req;
        _req.clear();
    }

private:
    std::string _req;
    std::string _method;
    std::string _uri;
    std::string _version;
    std::vector<std::string> _header;
    std::string _body;
};

class HttpResponse
{

public:
    HttpResponse(const HttpRequest &req) : _req(req) {}

    std::string Get_Content(std::string path)
    {
        std::string content;
        std::ifstream in(path, std::ios::binary);
        if (!in.is_open())
        {
            // LOG(logLevel::ERROR) << "open uri file error";
            return std::string();
        }
        in.seekg(0, in.end);
        int filesize = in.tellg();
        in.seekg(0, in.beg);

        content.resize(filesize);
        in.read((char *)content.c_str(), filesize);
        in.close();
        LOG(logLevel::DEBUG) << "content length: " << content.size();
        return content;
    }
    void Build()
    {
        std::string path = root + _req.GetUri();
        if(path.back()=='/')
        {
            path += home;
        }
        _content = Get_Content(path);
        _code = 200;
        _code_sta = "OK";
        if (_content.empty())
        {
            _content = Get_Content(page404);
            _code = 404;
            _code_sta = "Not Found";
        }
        _header.emplace_back("Content-Length" + miniSep + std::to_string(_content.size()));
        _header.emplace_back("Content-Type" + miniSep + "text/html");
        _version = "HTTP/1.1";
        _body = _content;
    }

    void Serialize(std::string *out)
    {
        std::string message = _version + Space + std::to_string(_code) + Space + _code_sta + Sep;
        for (int i = 0; i < _header.size(); ++i)
        {
            message += _header[i] + Sep;
        }
        message += Sep;
        message += _body;
        *out = message;
    }

private:
    std::string _version;
    int _code;
    std::string _code_sta;
    std::vector<std::string> _header;
    std::string _content;
    std::string _body;

private:
    HttpRequest _req;
};