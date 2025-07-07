
class Solution {
public:
    std::vector<int> cache;
    int numTrees(int n) {
        cache.resize(n+1,-1);
        cache[0]=1;
        return num(n);
    }
    int num(int n)
    {
        if(n==0){
            return 1;
        }
        if(cache[n]!=-1){
            return cache[n];
        }
        int res = 0;
        for(int i=1;i<=n;++i)
        {
            res += num(i-1) * num(n-i);
        }
        cache[n]=res;
        return res;
    }
};