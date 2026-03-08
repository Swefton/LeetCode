class Solution {
public:
    void backtrack(int l, int r, vector<string>& results, string state="") {
        if (l == 0 && r == 0) {
            results.push_back(state);
            return;
        }

        if (l > 0) backtrack(l-1, r, results, state+'(');
        if (r > l) backtrack(l, r-1, results, state+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;

        backtrack(n, n, results);

        return results;
    }
};