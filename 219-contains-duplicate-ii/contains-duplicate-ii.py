class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return False

        left, curr = 0, set([nums[0]])

        for right in range(1, len(nums)):
            while (right - left) > k:
                curr.remove(nums[left])
                left += 1
                curr.add(nums[left])

            if nums[right] in curr:
                return True
            else:
                curr.add(nums[right])

        return False
        