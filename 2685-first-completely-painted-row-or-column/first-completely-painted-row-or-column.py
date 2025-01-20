class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        
        positions = {}
        for i in range(m):
            for j in range(n):
                positions[mat[i][j]] = (i, j)
        
        row_count = [0] * m
        col_count = [0] * n
        
        for index in range(len(arr)):
            value = arr[index]
            x, y = positions[value]
            
            row_count[x] += 1
            col_count[y] += 1
            
            if row_count[x] == n or col_count[y] == m:
                return index
        
        return -1