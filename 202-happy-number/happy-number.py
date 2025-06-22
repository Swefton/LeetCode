class Solution:
    def isHappy(self, n: int) -> bool:
        visited = set()
        while True:
            int_list = [int(x) for x in str(n)]
            num = sum([x**2 for x in int_list])
            if num == 1:
                return True
            elif num in visited:
                return False
            else:
                visited.add(num)
                n = num
