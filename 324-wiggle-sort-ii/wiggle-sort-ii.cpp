class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int left = (n + 1) / 2 - 1; 
        int right = n - 1;

        for (int i = 0; i < n; ++i) {
            nums[i] = (i % 2 == 0) ? sorted[left--] : sorted[right--];
        }
    }
};