class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n < 4:
            return []

        nums.sort()
        results = []

        for first in range(n - 3):
            if first > 0 and nums[first] == nums[first - 1]:
                continue

            for second in range(first + 1, n - 2):
                if second > first + 1 and nums[second] == nums[second - 1]:
                    continue

                third, fourth = second + 1, n - 1

                while third < fourth:
                    total = nums[first] + nums[second] + nums[third] + nums[fourth]

                    if total < target:
                        third += 1
                    elif total > target:
                        fourth -= 1
                    else:
                        results.append([nums[first], nums[second], nums[third], nums[fourth]])

                        third += 1
                        fourth -= 1

                        while third < fourth and nums[third] == nums[third - 1]:
                            third += 1
                        while third < fourth and nums[fourth] == nums[fourth + 1]:
                            fourth -= 1

        return results
