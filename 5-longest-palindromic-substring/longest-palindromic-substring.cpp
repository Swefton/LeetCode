class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // starting case
        int start = 0;
        int maxLength = 1;

        // initialize the DP table
        bool dp[n][n];
        fill_n(&dp[0][0], n*n, false);

        // every single character is a palindrome in base
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // check for lengths 2+
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j]) {
                    if (length == 2 || dp[i + 1][j-1]) {
                        dp[i][j] = true;
                        if (length > maxLength) {
                            start = i;
                            maxLength = length;
                        }
                    }
                }

            }
        }

        return s.substr(start, maxLength);
    }
};