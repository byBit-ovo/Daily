class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        cache = {}
        def dp(i, j,myTurn)->int:
            if i > j:
                return 0
            if (i,j,myTurn) in cache:
                return cache[(i,j,myTurn)]
            res = 0
            if myTurn:
                left = nums[i] + dp(i+1, j,not myTurn)
                right = nums[j] + dp(i, j-1,not myTurn)
                cache[(i,j,myTurn)] = max(left, right)
            else:
                left = -nums[i] + dp(i+1, j,not myTurn)
                right = -nums[j] + dp(i, j-1,not myTurn)
                cache[(i,j,myTurn)] = min(left, right)
            return cache[(i,j,myTurn)]
        res = dp(0,len(nums)-1,True)
        return res >= 0

        
