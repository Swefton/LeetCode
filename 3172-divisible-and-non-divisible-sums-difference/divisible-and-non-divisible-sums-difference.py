class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        divisble = list()
        non_divisible = list()

        for i in range(1, n+1):
            if i%m == 0:
                divisble.append(i)
            else:
                non_divisible.append(i)
        
        return sum(non_divisible) - sum(divisble)