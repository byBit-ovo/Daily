class Solution:
    def maxProfit(self, prices: list[int], fee: int) -> int:
        cache = {}
        def dp(i,buy):
            if i  >= len(prices):
                return 0
            if (i,buy) in cache:
                return cache[(i,buy)]
            if buy:
                p1 = -prices[i] + dp(i+1,not buy) #选择买
                p2 = dp(i+1,buy)
                cache[(i, buy)] = max(p1, p2)
            else:
                p1 = prices[i] + dp(i+1, not buy) - fee #选择卖
                p2 = dp(i+1, buy)
                cache[(i, buy)] = max(p1, p2)
                
            return cache[(i,buy)]
        return dp(0,True)
    def maxProfit(self, prices: list[int], fee: int) -> int:
        dp = [[0]*2 for _ in range(len(prices))]
        dp[0][0] = 0
        dp[0][1] = -prices[0]
        # 0 手里没股票
        # 1 手里有股票
        for i in range(1,len(prices)):
            dp[i][0] = max(prices[i] - fee + dp[i-1][1], dp[i-1][0])
            dp[i][1] = max(-prices[i] + dp[i-1][0], dp[i-1][1])
        return dp[-1][0]






