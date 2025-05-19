#include <string>
#include <unordered_map>
#include <fstream>
const std::string path = "./";
const std::string file_name = "dict.txt";
const std::string sep = ":";

class dictionary
{
public:
    dictionary() { loadDict(); }
    ~dictionary() {}

    std::string find(const std::string& key)
    {
        for(auto& e:_dict)
        {
            if(e.first==key)
            {
                return e.second;
            }
        }
        return "目前无此单词";
    }

private:
    void loadDict()
    {
        std::ifstream reader(path + file_name);
        if(!reader.is_open())
        {
            LOG(logLevel::ERROR) << "dict.txt打开错误";
            exit(1);
        }
        std::string s;
        while (std::getline(reader, s))
        {
            int pos = s.find(sep);
            if (pos == std::string::npos)
            {
                continue;
            }
            std::string key = s.substr(0, pos);
            std::string value = s.substr(pos + sep.size());
            _dict[key] = value;
        }
    }
    std::unordered_map<std::string, std::string> _dict;
};
