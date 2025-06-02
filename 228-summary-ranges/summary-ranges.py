class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = list()
        index = 0

        while index != len(nums):
            start = index

            while index+1 < len(nums) and nums[index+1] == nums[index] + 1:
                index += 1

            if start == index:
                result.append(str(nums[start]))
            else:
                result.append(str(nums[start]) + "->" + str(nums[index]))
            
            index += 1


        return result
        