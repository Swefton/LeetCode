static unordered_map<char, string> phoneMap {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    void backtrack(string state, string digits, vector<string> &solution) {
        if (state.length() == digits.length()) {
            solution.push_back(state);
            return;
        }

        char digit = digits[state.length()];
        string letters = phoneMap[digit];

        for (char c : letters) {
            backtrack(state + c, digits, solution);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> results{};
        backtrack("", digits, results);

        return results;
    }
};