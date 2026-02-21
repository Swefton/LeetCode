class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        unsigned long left{0}, right{matrix.size()-1};
        while (left < right) {
            int top = left;
            int bottom = right;

            for (int i = 0; i < right - left ; ++i )
            {

            int temp = matrix[top][left+i];

            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = temp;

            }

            ++left;
            --right;
        }
    }
};