class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        cache = {}
        def dp(i, buy, k):
            if i >= len(prices) or k <= 0:
                return 0
            if (i,buy,k) in cache:
                return cache[(i,buy,k)]
            res = 0
            if buy:
                res = max(
                    -prices[i] + dp(i+1, not buy, k), 
                    dp(i+1, buy, k)
                    )
            else:
                res = max(
                    prices[i] + dp(i+1, not buy, k-1), 
                    dp(i+1, buy, k)
                    )
            cache[(i,buy,k)] = res
            return res
        return dp(0,True,k)
