#pragma once
#include "Protocol.hpp"

class Service
{
public:
    std::string parse(std::string &package)
    {
        std::string message;
        if (!Encrypton::Decode(package, message))
            return std::string();
        // message :: {json}
        Request req;
        req.Deserialize(message);
        Response res;
        switch (req.OPER())
        {
        case '+':
            res.SetResult(req.X() + req.Y());
            break;
        case '-':
            res.SetResult(req.X() - req.Y());

            break;
        case '*':
            res.SetResult(req.X() * req.Y());

            break;
        case '/':
            if (req.Y() == 0)
            {
                res.SetCode(1);
            }
            else
            {
                res.SetResult(req.X() / req.Y());
            }
            break;
        case '%':
            if (req.Y() == 0)
            {
                res.SetCode(2);
            }
            else
            {
                res.SetResult(req.X() % req.Y());
            }
            break;
        default:
            res.SetCode(3);
        }
        std::string ret;
        if(!res.Serialize(ret))
            return "";
        if(!Encrypton::Encode(ret))
            return "";
        return ret;
    }
};