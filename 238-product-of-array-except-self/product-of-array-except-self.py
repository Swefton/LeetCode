class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = list()

        product = 1
        for i in nums:
            product *= i
            result.append(product)
        
        product = 1
        for i in reversed(range(len(nums))):
            result[i] = (result[i-1] if i > 0 else 1) * product
            product *= nums[i]

        return result
        