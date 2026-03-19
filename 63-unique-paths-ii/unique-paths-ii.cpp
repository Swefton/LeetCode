class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1) return 0;

        obstacleGrid[0][0] = 1;

        for (int j = 1; j < cols; ++j) {
            if (obstacleGrid[0][j] == 1 || obstacleGrid[0][j-1] == 0) {
                obstacleGrid[0][j] = 0;
            } else {
                obstacleGrid[0][j] = 1;
            }
        }

        for (int i = 1; i < rows; ++i) {
            if (obstacleGrid[i][0] == 1 || obstacleGrid[i-1][0] == 0) {
                obstacleGrid[i][0] = 0;
            } else {
                obstacleGrid[i][0] = 1;
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }

        return obstacleGrid[rows-1][cols-1];
    }
};