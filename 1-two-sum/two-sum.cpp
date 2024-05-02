
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndices;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int compliment = target - nums[i];
            if (numIndices.find(compliment) != numIndices.end()){
                result.push_back(numIndices[compliment]);
                result.push_back(i);
            }            
            numIndices[nums[i]] = i;
        }
        return result;
    }
};