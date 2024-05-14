class Solution {
public:
    int getMaximumHelper(std::vector<std::vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[y][x] == 0) return 0;
        
        int gold = grid[y][x];
        grid[y][x] = 0;
        
        int maxGold = 0;
        maxGold = max(maxGold, gold + getMaximumHelper(grid, x+1, y));
        maxGold = max(maxGold, gold + getMaximumHelper(grid, x-1, y));
        maxGold = max(maxGold, gold + getMaximumHelper(grid, x, y+1));
        maxGold = max(maxGold, gold + getMaximumHelper(grid, x, y-1));
        
        grid[y][x] = gold;
        
        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for (int y = 0; y < grid.size(); ++y) {
            for (int x = 0; x < grid[0].size(); ++x) {
                maxGold = max(maxGold, getMaximumHelper(grid, x, y));
            }
        }
        return maxGold;
    }
};
