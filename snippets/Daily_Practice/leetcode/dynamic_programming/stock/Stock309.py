class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 0 : 已买入状态
        # 1 : 可买入状态
        # 2 : 冷冻期
        cache = {}
        def dp(i , sta):
            if i >= len(prices):
                return 0
            if (i, sta) in cache:
                return cache[(i, sta)]
            if sta == 0:
                sell = prices[i] + dp(i+1, 2)
                rest = dp(i+1, 0)
                cache[(i, sta)] = max(sell, rest)
            elif sta == 1:
                buy = -prices[i] + dp(i+1, 0)
                rest = dp(i+1, 1)
                cache[(i, sta)] = max(buy, rest)
            else:
                cache[(i, sta)] = dp(i+1, 1)
            return cache[(i,sta)]
        return dp(0,1)
