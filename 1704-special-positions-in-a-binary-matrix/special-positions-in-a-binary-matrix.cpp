class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int specialPos = 0;
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> rowSum(rows, 0);
        vector<int> colSum(cols, 0);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    specialPos++;
                }
            }
        }

        return specialPos;
    }
};