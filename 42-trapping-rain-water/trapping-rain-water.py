class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        left_val = height[l]
        right_val = height[r]
        vol = 0

        while(l < r):
            if(left_val >= right_val): #case 1
                r = r-1
                if(height[r] < right_val):
                    vol = vol + right_val - height[r]
                else:
                    right_val = height[r]
                
            elif(left_val < right_val): #case 2
                l = l + 1
                if(height[l] < left_val):
                    vol = vol + left_val - height[l]
                else:
                    left_val = height[l]
                
        return vol