class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = {0:1}
        sum, res = 0, 0
        for x in nums:
            sum += x
            if sum-k in count:
                res += count[sum-k]
            count[sum] = count.get(sum, 0) + 1
        return res

        
