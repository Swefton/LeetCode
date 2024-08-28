class Solution:
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        def dfs(r, c):
            if (r < 0 or r >= len(grid2) or c < 0 or c >= len(grid2[0]) 
                or grid2[r][c] == 0 or (r, c) in visited):
                return True
            
            visited.add((r, c))
            
            is_sub_island = grid1[r][c] == 1
            
            is_sub_island = dfs(r+1, c) and is_sub_island
            is_sub_island = dfs(r-1, c) and is_sub_island
            is_sub_island = dfs(r, c+1) and is_sub_island
            is_sub_island = dfs(r, c-1) and is_sub_island
            
            return is_sub_island

        visited = set()
        sub_island_count = 0
        
        for r in range(len(grid2)):
            for c in range(len(grid2[0])):
                if grid2[r][c] == 1 and (r, c) not in visited:
                    if dfs(r, c):
                        sub_island_count += 1
        
        return sub_island_count
