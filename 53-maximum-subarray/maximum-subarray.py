class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        result = -float('inf')
        total = 0

        for i in nums:
            if total < 0:
                total = 0

            total += i

            result = max(result, total)

        return result
        
