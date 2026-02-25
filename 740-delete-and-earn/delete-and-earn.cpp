class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, int> numCount;
    for (int num : nums) numCount[num]++;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int prevLast = 0; // Represents dp[i-2]
    int last = 0;     // Represents dp[i-1]

    for (int i = 0; i < nums.size(); ++i) {
        int currNum = nums[i];
        int currEarn = currNum * numCount[currNum];

        int temp = last;
        if (i > 0 && currNum == nums[i - 1] + 1) {
            // Can't take both i and i-1
            last = max(currEarn + prevLast, last);
        } else {
            // Not adjacent, take current + all previous best
            last += currEarn;
        }
        prevLast = temp;
    }

    return last;
}
};