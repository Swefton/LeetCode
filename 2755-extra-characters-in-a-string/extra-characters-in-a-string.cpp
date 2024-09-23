#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
        int n = s.length();
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                std::string substring = s.substr(j, i - j);
                if (dict.count(substring)) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};
