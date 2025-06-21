class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        hops = 0
        farthest = 0
        end = 0

        for i in range(n - 1):
            farthest = max(farthest, i + nums[i])
            if i == end:
                hops += 1
                end = farthest

        return hops
