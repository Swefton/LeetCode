class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        markers = list()
        visited_row, visited_col = set(), set()

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    markers.append((i,j))

        print(markers)

        for marker in markers:
            if marker[0] not in visited_row:
                for i in range(len(matrix[0])):
                    matrix[marker[0]][i] = 0
            if marker[1] not in visited_col:
                for i in range(len(matrix)):
                    matrix[i][marker[1]] = 0

            visited_row.add(marker[0])
            visited_col.add(marker[1])
