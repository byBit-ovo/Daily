class Solution {
public:
    string dynamicPassword(string password, int target) {
        int len = password.size();
        target %= len;
        reverse(password.begin(), password.end());
        reverse(password.end() - target, password.end());
        reverse(password.begin(), password.end() - target);
        return password;
    }
};
class Solution {
public:
    string dynamicPassword(string password, int target) {
        target %= password.size();
        string res;
        for(int i =target;res.size() != password.size();++i)
        {
            res += password[i%password.size()];
        }
        return res;
    }
};
class Solution {
public:
    string dynamicPassword(string password, int target) {
        string sub = password.substr(0,target);
        password.erase(0,target);
        password+=sub;

        return password;
    }
};
