class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    left[j] = dp[j];
                } else {
                    left[j] = max(left[j-1] - 1, dp[j]);
                }
            }
            
            for (int j = n-1; j >= 0; --j) {
                if (j == n-1) {
                    right[j] = dp[j];
                } else {
                    right[j] = max(right[j+1] - 1, dp[j]);
                }
            }
            
            for (int j = 0; j < n; ++j) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
