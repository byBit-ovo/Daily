class Solution {
public:
    int dp[101]={0};
    int fib(int n) {
        if(n<2){
            dp[n]=n;
            return n;
        }
        if(dp[n]!=0) return dp[n];//查找备忘录
        //如果备忘录里没有，先添加到备忘录，为再次查找做准备，不在做重复性工作
        dp[n-1] = fib(n-1);
        dp[n-2] = fib(n-2);
        return (dp[n-1] + dp[n-2]);
    }
};

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int a = 0;
        int b = 1;
        int c = a+b;
        for(int i=0;i<=n-2;++i){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};

int digit_sum(int n){
    if(n==0) return 0;
    return n%10 +digit_sum(n/10);
}

