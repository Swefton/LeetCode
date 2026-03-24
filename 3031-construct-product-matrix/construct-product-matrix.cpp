class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        constexpr int mod = 12345;
        vector<vector<int>> res(m, vector<int>(n));
        long long runningProduct = 1;

        // Prefix Pass
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = runningProduct;
                runningProduct = (runningProduct * (grid[i][j] % mod)) % mod;
            }
        }

        runningProduct = 1;
        // Suffix Pass
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                res[i][j] = (res[i][j] * runningProduct) % mod;
                runningProduct = (runningProduct * (grid[i][j] % mod)) % mod;
            }
        }

        return res;
    }
};