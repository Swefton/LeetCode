class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result, majority = 0, 0
        
        for num in nums:
            if majority == 0:
                result = num
            
            majority += 1 if num == result else -1
        
        return result