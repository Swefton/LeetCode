class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        displacement = k % len(nums)

        
        if displacement != 0:
            nums[:0] = nums[-displacement:]
            del nums[-displacement:]
        

        return
        