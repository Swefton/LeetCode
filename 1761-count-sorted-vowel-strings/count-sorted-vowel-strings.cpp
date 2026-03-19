class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 3; j >= 0; --j) {
                dp[j] += dp[j + 1];
            }
        }

        int total = 0;
        for (int count : dp) total += count;
        return total;
    }
};