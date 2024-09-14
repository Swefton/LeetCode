class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currentLen = 0;

        for (int num : nums) {
            if (num == maxNum) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }

        return maxLen;
    }
};
