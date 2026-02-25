class Solution {
public:
    int rob(vector<int>& nums) {
       int behindPrev{}, prev{};
       for (auto i : nums) {
        int temp = max(behindPrev+i, prev);
        behindPrev = prev;
        prev = temp;
       }
       return prev;
    }
};