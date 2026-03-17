class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prevHeights = matrix[0];
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) {
                        prevHeights[j] = matrix[i][j] ? prevHeights[j] + 1 : 0;
                    }
                }
                auto temp = prevHeights;
                ranges::sort(temp, std::greater{});

                for (int pos = 0; pos < n; ++pos) maxArea = max(maxArea, temp[pos] * (pos+1));
            }
        
        return maxArea;
    }
};