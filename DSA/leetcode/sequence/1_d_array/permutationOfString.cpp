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

//python
//class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if(len(s2) < len(s1)): return False
        s1Count,s2Count = [0]*26,[0]*26
        for i in range(len(s1)):
            s1Count[ord(s1[i])-ord('a')]+=1
            s2Count[ord(s2[i])-ord('a')]+=1
        matches = 0
        for i in range(26):
            if(s1Count[i]==s2Count[i]):
                matches += 1
        i,j = 0,len(s1)
        while j < len(s2):
            if matches==26: return True
            index = ord(s2[j]) - ord('a')
            s2Count[index]+=1
            if s2Count[index]==s1Count[index]:
                matches+=1
            elif s2Count[index]-1 == s1Count[index]:
                matches-=1
            j+=1
            index = ord(s2[i]) - ord('a')
            s2Count[index]-=1
            if s2Count[index]==s1Count[index]:
                matches+=1
            elif s2Count[index]+1==s1Count[index]:
                matches-=1
            i+=1
        return matches==26




