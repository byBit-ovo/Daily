#pragma once
#include <string>
#include "inet_addr.hpp"
#include <memory>
#include <list>

class User;
class UserInterface
{
public:
    virtual ~UserInterface() {}
    virtual bool operator==(const User &other) = 0;
    virtual void SendTo(int socket, const std::string &message) = 0;
    virtual std::string name() const = 0;
};

class User : public UserInterface
{
public:
    User(const netAddr &other) : _addr(other) {}
    User(const User &other) : _addr(other._addr) {}
    User(const std::string &ip, uint16_t port) : _addr(ip, port) {}
    std::string name() const { return _addr.name(); }

    bool operator==(const User &other) override
    {
        return _addr == other._addr;
    }

    void SendTo(int socket, const std::string &message) override
    {
        LOG(logLevel::DEBUG) << "send message(" << message << ") to " << _addr.name();
        int n = ::sendto(socket, message.c_str(), message.size(), 0, &_addr, _addr.size());
    }

private:
    netAddr _addr;
};

class UserManager
{
public:
    bool AddUser(const User &user)
    {
        lockGuard guard(_lock);
        for (auto p : _Online_Users)
        {
            if (p->name() == user.name())
            {
                LOG(logLevel::INFO) << "用户 " << user.name() << "已经存在";
                return false;
            }
        }

        _Online_Users.push_back(std::make_shared<User>(user));
        LOG(logLevel::INFO) << "新增用户 " << user.name();
        LOG(logLevel::INFO) <<"共有"<<_Online_Users.size()<<"个用户在线";
        return true;
    }

    bool DelUser(const User &user)
    {
        lockGuard guard(_lock);
        for (auto p : _Online_Users)
        {
            if (p->name() == user.name())
            {
                std::string leave = user.name();
                _Online_Users.remove(p);
                LOG(logLevel::INFO) << "移除用户 " << user.name();
                LOG(logLevel::INFO) <<"共有"<<_Online_Users.size()<<"个用户在线";
                return true;
            }
        }
        LOG(logLevel::INFO) << "要移除的用户" << user.name() << "不存在";
        return false;
    }
    void BroadCast(int socket, const std::string &message, const User &self)
    {
        lockGuard guard(_lock);
        for (auto e : _Online_Users)
        {
            if (e->name() != self.name())
            {
                e->SendTo(socket, message);
            }
        }
    }

private:
    std::list<std::shared_ptr<UserInterface>> _Online_Users;
    mutex _lock;
};