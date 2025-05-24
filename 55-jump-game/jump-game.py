class Solution:
    def canJump(self, nums: List[int]) -> bool:
        curr = 0
        
        while curr < len(nums) - 1:
            if nums[curr] == 0:
                return False
            
            max_reach = 0
            best_index = curr
            for i in range(1, nums[curr] + 1):
                if curr + i >= len(nums) - 1:
                    return True
                if curr + i + nums[curr + i] > max_reach:
                    max_reach = curr + i + nums[curr + i]
                    best_index = curr + i
            
            curr = best_index

        return True
