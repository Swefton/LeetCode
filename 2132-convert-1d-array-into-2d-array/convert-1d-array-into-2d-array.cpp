class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if (original.size() != m*n) return result;

        vector<int>::iterator curr = original.begin();
        while (curr != original.end()) {
            vector<int> row;
            for (int i = 0; i < n; ++i) {
                row.push_back(*curr);
                ++curr;
            }
            result.push_back(row);
        }
        return result;
    }
};