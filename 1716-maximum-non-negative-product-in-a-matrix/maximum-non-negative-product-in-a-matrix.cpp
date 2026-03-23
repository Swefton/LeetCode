class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bestTrack>> dp(m, vector<bestTrack>(n));

        // initialize base square
        dp[0][0] = {(long)grid[0][0], (long)grid[0][0]};

        // initialize first row
        for (int j = 1; j < n; ++j) {
            long val = dp[0][j - 1].max * grid[0][j];
            dp[0][j] = {val, val};
        }

        // initialize first col
        for (int i = 1; i < m; ++i) {
            long val = dp[i-1][0].max * grid[i][0];
            dp[i][0] = {val, val};
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                long cur = grid[i][j];
                
                // Candidates from top and left
                long c1 = cur * dp[i-1][j].max;
                long c2 = cur * dp[i-1][j].min;
                long c3 = cur * dp[i][j-1].max;
                long c4 = cur * dp[i][j-1].min;

                dp[i][j].max = max({c1, c2, c3, c4});
                dp[i][j].min = min({c1, c2, c3, c4});
            }
        }

        long long finalMax = dp[m-1][n-1].max;
        if (finalMax < 0) return -1;

        return finalMax % 1000000007;
    }

private:
    struct bestTrack {
        long max = -1e9;
        long min = 1e9;
    };
};