class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return

        columns = list()
        for col in range(len(matrix)):
            columns.append([i[col] for i in matrix][::-1])

        matrix[:] = columns

        