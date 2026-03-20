class Solution {
public:
    bool isPalindrome(int x) {
        string strNum = to_string(x);

        auto left = strNum.begin();
        auto right = strNum.end() - 1;

        while (left < right) {
            if (*left != *right) return false;

            left++;
            right--;
        }

        return true;
    }
};