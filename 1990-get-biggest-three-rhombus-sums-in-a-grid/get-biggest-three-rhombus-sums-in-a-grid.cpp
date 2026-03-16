class Solution {
public:
    int sumRhombus(const vector<vector<int>>& grid, int r, int c, int s) {
        /*
        center = [3][5]
        size = 2

        clockwise from top
        [1][5]
        [2][6]
        [3][7]
        [4][6]
        [5][5]
        [4][4]
        [3][3]
        [2][4]
        */

        if (s == 0)
            return grid[r][c];
        int totalSum = 0;

        // 1. Top to Right
        for (int i = 0; i < s; ++i)
            totalSum += grid[r - s + i][c + i];

        // 2. Right to Bottom
        for (int i = 0; i < s; ++i)
            totalSum += grid[r + i][c + s - i];

        // 3. Bottom to Left
        for (int i = 0; i < s; ++i)
            totalSum += grid[r + s - i][c - i];

        // 4. Left to Top
        for (int i = 0; i < s; ++i)
            totalSum += grid[r - i][c - s + i];

        return totalSum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int, vector<int>, greater<int>> maxSums{};

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int biggest = min({m - i - 1, i, n - j - 1, j});

                for (int s = biggest; s >= 0; --s) {
                    int currentSum = sumRhombus(grid, i, j, s);

                    maxSums.push(currentSum);
                }
            }
        }

        vector<int> result;
        while (!maxSums.empty()) {
            int current = maxSums.top();
            maxSums.pop();

            if (result.empty() || current != result.back()) {
                result.push_back(current);
            }

            if (result.size() > 3) {
                result.erase(result.begin());
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};