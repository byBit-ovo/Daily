#3852
class Solution:
    def minDistinctFreqPair(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        mn = min(nums)

        cnt_min = cnt[mn]
        min_y = min((y for y, c in cnt.items() if c != cnt_min), default=None)

        if min_y is None:
            return [-1, -1]
        return [mn, min_y]

