class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        low = prices[0]
        profit = 0
        for p in prices :
            low = min(p, low)
            profit  = max(profit, p - low)
        return profit
        