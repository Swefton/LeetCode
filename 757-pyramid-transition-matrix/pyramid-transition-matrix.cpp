class Solution {
public:
    unordered_map<string, vector<char>> allowedBots;
    unordered_map<string, bool> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const string& block : allowed) {
            allowedBots[block.substr(0, 2)].push_back(block[2]);
        }
        return solve(bottom, "");
    }

    bool solve(string curr, string next) {
        // Base case: pyramid completed
        if (curr.size() == 1) return true;
        
        // Current row finished, move to the next level
        if (next.size() == curr.size() - 1) return solve(next, "");

        string state = curr + "#" + next;
        if (memo.contains(state)) return memo[state];

        // Get the pair of blocks from the current row
        string base = curr.substr(next.size(), 2);
        
        if (allowedBots.contains(base)) {
            for (char c : allowedBots[base]) {
                if (solve(curr, next + c)) return memo[state] = true;
            }
        }
        
        return memo[state] = false;
    }
};