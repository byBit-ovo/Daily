class Solution {
public:
    vector<vector<int>> cache;
    string s,t;

    int numDistinct(string ss, string tt) {
        int s_len = ss.size(),t_len=tt.size();
        if(s_len<t_len){
            return 0;
        }
        s=ss,t=tt;
        cache.resize(s_len,vector<int>(t_len,-1));
        return dp(s_len-1,t_len-1);
    }
    int dp(int tails,int tailt){
        if(tailt<0) return 1;
        if(tails<0) return 0;
        if(cache[tails][tailt]!=-1){
            return cache[tails][tailt];
        }
        int res = 0;
        if(s[tails]==t[tailt]){
            res+=dp(tails-1,tailt-1);
        }
        res+=dp(tails-1,tailt);
        cache[tails][tailt]=res;
        return res;
    }
};
