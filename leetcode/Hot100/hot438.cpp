#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window;
        unordered_map<char,int> pCount;
        for(char c : p) ++pCount[c];
        int match = 0;
        vector<int> res;
        for(int i=0,j=0;j<s.size();++j)
        {
            ++window[s[j]];
            if(pCount.count(s[j]) && window[s[j]] == pCount[s[j]]){
                match+=1;
            }
            if(j - i + 1 > p.size()){
                --window[s[i]];
                if(pCount.count(s[i]) && window[s[i]] == pCount[s[i]] - 1){
                    --match;
                }
                ++i;
            }
            if(match == pCount.size()){
                res.push_back(i);
            }
        }
        return res;
    }
};
int main()
{
    Solution tool;
    std::vector<int> v = tool.findAnagrams("cbaebabacd","abc");
    for(int n : v){
        std::cout<<n<<" ";
    }
    std::cout<<std::endl;
    return 0;
}