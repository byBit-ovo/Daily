class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prefix = nums[0]
        res = nums[0]
        for n in nums[1:]:
            if prefix >= 0:
                res = max(res, prefix+n)
                prefix += n
            else:
                res = max(res, n)
                prefix = n
        return res
            
        
