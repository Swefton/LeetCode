class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    int sides = 4;
                    int dirs[2][2] = {{-1,0},{0,-1}};
                    
                    for (auto [dirY, dirX] : dirs) {
                        if (i+dirY >= 0 && i+dirY < grid.size() && j+dirX >= 0 && j+dirX < grid[0].size() && grid[i+dirY][j+dirX]) sides -= 2;
                    }

                    perimeter += sides;
                }
            }
        }

        return perimeter;
    }
};