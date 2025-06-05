class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        result = ""
        lists = [[] for _ in range(numRows)]

        count = 0
        down = True

        for letter in s:
            lists[count].append(letter)

            if down:
                count += 1
            else:
                count -= 1

            if count == numRows:
                count = numRows - 2
                down = False
            elif count == -1:
                count = 1
                down = True

        
        for i in lists:
            result += "".join(i)

        return result