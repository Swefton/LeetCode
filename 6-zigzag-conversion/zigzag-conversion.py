class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        lists = ["" for _ in range(numRows)]

        count = 0
        down = True

        for letter in s:
            lists[count] += letter

            count += 1 if down else -1

            if count == numRows:
                count = numRows - 2
                down = False
            elif count == -1:
                count = 1
                down = True

        return "".join(lists)