from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Merge nums2 into nums1 as one sorted array using a temporary array.
        """
        l, r = 0, 0
        temp = []

        while l < m and r < n:
            if nums1[l] < nums2[r]:
                temp.append(nums1[l])
                l += 1
            else:
                temp.append(nums2[r])
                r += 1

        while l < m:
            temp.append(nums1[l])
            l += 1

        while r < n:
            temp.append(nums2[r])
            r += 1

        for i in range(len(temp)):
            nums1[i] = temp[i]
