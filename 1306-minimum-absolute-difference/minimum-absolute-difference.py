class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        if len(arr) < 2:
            return list()


        arr.sort()
        vals = set(arr)
        results = []
        smallest = min([abs(arr[i]- arr[i+1]) for i in range(len(arr)-1)])

        for i in arr:
            if i-smallest in vals:
                results.append([i-smallest, i])

        return results
