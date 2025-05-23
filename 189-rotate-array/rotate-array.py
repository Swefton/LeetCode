class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        displacement = k % len(nums)

        rotated_elements = nums[-displacement:]

        del nums[-displacement:]
        
        nums[:0] = rotated_elements



        return
        