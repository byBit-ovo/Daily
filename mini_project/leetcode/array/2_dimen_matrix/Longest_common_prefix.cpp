class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int min_len = strs[0].size();
        for(int i=0;i<strs.size();++i)
        {
            if(strs[i].size() < min_len)
            {
                min_len = strs[i].size();
            }
        }

        int i=0,j=0;
        for(;i<min_len;++i)
        {
            char c = strs[0][i];
            for(j=0;j<strs.size();++j)            
            {
                if(strs[j][i] != c)
                {
                    return strs[0].substr(0,i);    
                }
            }
        }

        return strs[0].substr(0,i);
        
    }
};

