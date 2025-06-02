class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(cost) > sum(gas):
            return -1

        index, start = 0, 0
        total = 0

        while index != len(gas):
            total += gas[index] - cost[index]
            if total < 0:
                total = 0
                start = index + 1
            index += 1

        return start
        
        