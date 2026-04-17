class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 3) return max_element(nums.begin(), nums.end()) - nums.begin();

        int mid = nums.size() / 2;

        while (true) {
            if (mid == 0 || mid == nums.size()-1 || ((nums[mid-1] < nums[mid]) && (nums[mid] > nums[mid+1]))) return mid;
            mid += nums[mid+1] > nums[mid] ? 1 : -1;
        }

        return mid;
    }
};