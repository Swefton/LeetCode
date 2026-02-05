class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0
        
        def bfs(row,col):
            queue = deque([(row,col)])
            visited.add((row,col))

            while queue:
                curr_row, curr_col = queue.popleft()

                for dr, dc in [(0,1), (0,-1), (1,0), (-1,0)]:
                    nr, nc = curr_row + dr, curr_col + dc

                    if (0 <= nr < rows and 0 <= nc < cols) and grid[nr][nc] == "1" and (nr, nc) not in visited:
                        queue.append((nr, nc))
                        visited.add((nr, nc))
        
        for row in range(rows):
            for col in range(cols):
                print(row,col)
                if grid[row][col] == "1" and (row,col) not in visited:
                    bfs(row,col)
                    islands += 1

        return islands
