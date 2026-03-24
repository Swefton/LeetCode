class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(1,vector<int>(1,1));

        for (int i = 1; i < numRows; ++i) {
            int rows = i + 1;
            triangle.push_back(vector<int>(rows, 1));

            for (int j = 1; j < rows - 1; ++j) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }

        return triangle;
    }
};