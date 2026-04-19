class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> lastIndex;
        for (int i = 0; i < n; ++i) {
            lastIndex[nums[i]] = i;
        }

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int complement = -(nums[i] + nums[j]);
                
                if (lastIndex.count(complement) && lastIndex[complement] > j) {
                    result.push_back({nums[i], nums[j], complement});
                }
            }
        }

        return result;
    }
};