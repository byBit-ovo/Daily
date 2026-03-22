class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        exists = set()
        for n in nums:
            exists.add(n)
        for i in range(1,len(nums)+2):
            if i not in exists:
                return i
        return -1

        