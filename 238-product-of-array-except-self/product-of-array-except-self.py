class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = list()
        right = list()

        result = list()

        product = 1
        for i in nums:
            product *= i
            left.append(product)

        product = 1
        for i in nums[::-1]:
            product *= i
            right.append(product)
        
        right.reverse()

        for i in range(len(nums)):
            result.append((left[i-1] if i != 0 else 1) * (right[i+1] if i < len(nums)-1 else 1))

        return result
        