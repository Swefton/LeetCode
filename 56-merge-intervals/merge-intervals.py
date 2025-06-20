class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals
        
        intervals.sort(key = lambda x : x[0])
        result = list()
        curr = intervals[0]

        for i in intervals[1:]:
            if curr[0] <= i[0] <= curr[1]:
                curr[1] = max(i[1], curr[1])
            else:
                result.append(curr)
                curr = i

        result.append(curr)
        
        return result
        