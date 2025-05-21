class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = list()
        nums.sort()

        for index, number in enumerate(nums):
            if index > 0 and number == nums[index - 1]:
                continue
            
            left, right = index + 1, len(nums) - 1
            while left < right:
                sum_of_three = number + nums[left] + nums[right]

                if sum_of_three < 0:
                    left += 1
                elif sum_of_three == 0:
                    result.append([nums[index], nums[left], nums[right]])
                    left += 1
                    while nums[left] == nums[left - 1] and left < right:
                        left += 1 
                else:
                    right -= 1

        return result