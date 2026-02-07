class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols = len(board), len(board[0])
        dont_change = set()

        def bfs(row,col):
            if board[row][col] != "O" or (row, col) in dont_change:
                return
            
            queue = deque([(row, col)])
            dont_change.add((row, col))

            while queue:
                curr_row, curr_col = queue.popleft()

                for dr, dc in [(0,1), (0,-1), (1,0), (-1,0)]:
                    nr, nc = curr_row + dr, curr_col + dc
                    if (0 <= nr < rows and 0 <= nc < cols) and board[nr][nc] == "O" and (nr, nc) not in dont_change:
                        queue.append((nr, nc))
                        dont_change.add((nr, nc))
        
        for row in [0, rows-1]:
            for col in range(cols):
                bfs(row, col)
        
        for col in [0, cols-1]:
            for row in range(rows):
                bfs(row,col)
        
        print(dont_change)
        
        for row in range(rows):
            for col in range(cols):
                if board[row][col] == "O" and (row, col) not in dont_change:
                    board[row][col] = "X"
