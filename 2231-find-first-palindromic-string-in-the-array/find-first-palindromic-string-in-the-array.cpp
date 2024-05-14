class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto i : words) {
            if (i.size() == 1) return i;

            auto left = i.begin();
            auto right = i.end() - 1;

            while (left < right) {
                if (*left != *right) break;
                ++left;
                --right;
            }
            if (*left == *right) return i;
        }
        return "";
    }
};