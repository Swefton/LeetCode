class Solution {
private:
    void dfs(vector<vector<char>>& grid, size_t row, size_t col) {
        if (grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        pair<int,int> dirs[] = {make_pair(1,0), make_pair(-1,0), make_pair(0,-1), make_pair(0,1)};
        for (auto i : dirs) {
            size_t r{row+i.first}, c{col+i.second};
            if ((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size()) ) {
                dfs(grid,r,c);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount{0};

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid,i,j);
                }
            }
        }

        return islandCount;
    }
};