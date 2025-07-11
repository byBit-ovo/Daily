class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int valid = 0;
        unordered_map<char,int> wordInS1;
        unordered_map<char,int> window;
        for(auto c:s1){
            ++wordInS1[c];
        }

        for(int i = 0,j=0;i<s2.size();++i)
        {
            if(wordInS1.count(s2[i]))
            {
                ++window[s2[i]];
                if(window[s2[i]] <= wordInS1[s2[i]]){
                    ++valid;
                }
            }
            if(i-j+1 > s1.size()){
                if(wordInS1.count(s2[j])){
                    --window[s2[j]];
                    if(window[s2[j]] < wordInS1[s2[j]]){
                        --valid;
                    }
                }
                ++j;
            }
            if(valid==s1.size()){
                return true;
            }
            
        }
        return false;
    }
};
