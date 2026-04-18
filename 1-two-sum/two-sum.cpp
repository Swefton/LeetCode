
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;

        for (int i = 0; i < nums.size(); ++i) {
            int compliment = target - nums[i];
            if (numIndices.contains(compliment)) return {numIndices[compliment], i};
            numIndices[nums[i]] = i;
        }
        return {};
    }
};