class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        left, curr, best = -1, 0, math.inf

        for i in range(len(nums)):
            curr += nums[i]
            while curr >= target:
                best = min(best, i - left)
                left += 1
                curr -= nums[left]

        return best if best != math.inf else 0
