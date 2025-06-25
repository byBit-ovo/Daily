class Solution {
public:
    vector<vector<int>> cache;
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(),len2=text2.size();
        cache.resize(len1,vector<int>(len2,-1));
        return dp(text1,text2,len1-1,len2-1);
    }
    int dp(const string& s1,const string& s2,int i,int j)
    {
        if(i<0 || j<0){
            return 0;
        }
        if(cache[i][j]!=-1){
            return cache[i][j];
        }
        if(s1[i]==s2[j])
        {
            cache[i][j] =  1 + dp(s1,s2,i-1,j-1);
        }else{
            cache[i][j] = max(dp(s1,s2,i,j-1),dp(s1,s2,i-1,j));
        }
        return cache[i][j];
    }
};
