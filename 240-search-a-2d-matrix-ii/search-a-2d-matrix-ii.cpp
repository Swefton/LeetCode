class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (row.front() <= target && target <= row.back()) {
                if (ranges::binary_search(row, target)) return true;
            }
        }

        return false;
    }
};