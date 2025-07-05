class Solution:
    def findLucky(self, arr: List[int]) -> int:
        return max([x for x, c in Counter(arr).items() if x == c], default=-1)
        