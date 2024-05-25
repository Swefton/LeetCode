class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> result;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        if (dp[s.size()]) {
            vector<string> path;
            helper(s, wordSet, 0, path, result);
        }
        
        return result;
    }

private:
    void helper(string& s, unordered_set<string>& wordSet, int start, vector<string>& path, vector<string>& result) {
        if (start == s.size()) {
            result.push_back(path[0]);
            for (int i = 1; i < path.size(); i++) {
                result.back() += " " + path[i];
            }
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (wordSet.count(s.substr(start, i - start + 1))) {
                path.push_back(s.substr(start, i - start + 1));
                helper(s, wordSet, i + 1, path, result);
                path.pop_back();
            }
        }
    }
};