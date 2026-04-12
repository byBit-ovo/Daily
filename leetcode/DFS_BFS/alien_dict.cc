#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
class Solution1 {
    public:
        string alienOrder(vector<string>& words) {
            unordered_map<char, unordered_set<char>> neighbors;
            unordered_map<char, int> inDegree;
            for(int i = 0; i < words.size(); ++i)
            {
                for(int j = i + 1; j < words.size(); ++j)
                {
                    int d = 0;
                    int lim = min(words[i].size(), words[j].size());
                    while(d < lim)
                    {
                        if(words[i][d] != words[j][d])
                        {
                            if(neighbors[words[i][d]].insert(words[j][d]).second)
                            {
                                inDegree[words[j][d]] += 1;
                            }
                            break;
                        }
                        d += 1;
                    }
                    if (d == lim && words[i].size() > words[j].size()) {
                        return "";
                    }
                }
            }
            unordered_set<char> visited;
            queue<char> q; 
            for(int i = 0; i < words.size(); ++i)
            {
                for(char c : words[i])
                {
                    if(inDegree.contains(c) == false && visited.contains(c) == false)
                    {
                        q.push(c);
                        visited.insert(c);
                    }
                }
            }
            std::vector<char> res;
            while(q.empty() == false)
            {
                char c = q.front(); q.pop();
                res.push_back(c);
                for(char n: neighbors[c])
                {
                    inDegree[n] -= 1;
                    if(inDegree[n] == 0)
                    {
                        q.push(n);
                    }
                }
            }
            for(auto& p : inDegree)
            {
                if(p.second!=0)
                {
                    return "";
                }
            }
            return string(res.begin(), res.end());
        }
};
    
    
class Solution2 {
    public:
        unordered_map<char, unordered_set<char>> neighbors;
        unordered_map<char, int> inDegree;
        unordered_set<char> visited;
        unordered_set<char> inAns;
        string res;
        bool dfs(char c)
        {
            if(inAns.contains(c)) return true;
            if(visited.contains(c)) return false;

            unordered_set<char> &neis = neighbors[c];
            visited.insert(c);
            for(auto nxt : neis)
            {
                if(dfs(nxt) == false) return false;
            } 
            res = c + res;
            inAns.insert(c);
            visited.erase(c);
            return true;
        }
        string alienOrder(vector<string>& words) {
            for(string& s: words)
            {
                for(char c: s)
                {
                    inDegree[c] = 0;
                }
            }
            for(int i = 0; i < words.size(); ++i)
            {
                for(int j = i + 1; j < words.size(); ++j)
                {
                    int d = 0;
                    int lim = min(words[i].size(), words[j].size());
                    while(d < lim)
                    {
                        if(words[i][d] != words[j][d])
                        {
                            if(neighbors[words[i][d]].insert(words[j][d]).second)
                            {
                                inDegree[words[j][d]] += 1;
                            }
                            break;
                        }
                        d += 1;
                    }
                    if (d == lim && words[i].size() > words[j].size()) {
                        return "";
                    }
                }
            }

            for(auto &p: inDegree)
            {
                if(dfs(p.first) == false) return "";
            }
            return res;
            
        }
};
    
    
int main()
{
    Solution2 s;
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    string res = s.alienOrder(words);
    cout << res << endl;
    return 0;
}