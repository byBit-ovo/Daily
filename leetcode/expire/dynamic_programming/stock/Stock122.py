class Solution:
    def maxProfit(self, prices) -> int:
        profit = 0
        buy = prices[0]
        for p in prices:
            if p <= buy :
                buy = p
            else:
                profit += p  - buy
                buy = p
        return profit

a = [ [ [1]* 3 for _ in range(4)] for _ in range(5)] 
def t1(s):
    def t2(t):
        s = 1

        