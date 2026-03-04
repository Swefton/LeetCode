class Solution {
public:
    void backtracking(vector<int>& nums, vector<vector<int>>& results, int start) {
        if (start == nums.size()) {
            results.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtracking(nums, results, start + 1);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        backtracking(nums, results, 0);
        return results;
    }
};