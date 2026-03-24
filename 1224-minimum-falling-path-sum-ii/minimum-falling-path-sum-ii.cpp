class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        // m1: smallest sum, m2: second smallest sum, idx1: index of m1
        int m1 = 0, m2 = 0, idx1 = -1;

        for (int r = 0; r < n; ++r) {
            int curM1 = INT_MAX, curM2 = INT_MAX, curIdx1 = -1;

            for (int c = 0; c < n; ++c) {
                // If current column matches the previous min's column, use the second min
                int prevSum = (c != idx1) ? m1 : m2;
                int currentSum = grid[r][c] + prevSum;

                // Update the two smallest values for the current row
                if (currentSum < curM1) {
                    curM2 = exchange(curM1, currentSum);
                    curIdx1 = c;
                } else if (currentSum < curM2) {
                    curM2 = currentSum;
                }
            }
            m1 = curM1;
            m2 = curM2;
            idx1 = curIdx1;
        }

        return m1;
    }
};