class Solution {
public:
    struct state {
        int i;
        int j;
        int edits;

        bool operator>(const state& other) const {
            return edits > other.edits;
        }
    };
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // min_edits[i][j] stores the fewest edits found to reach indices (i, j)
        // We initialize with a large number
        vector<vector<int>> min_edits(n + 1, vector<int>(m + 1, 1e9));
        
        // Priority queue helps us always process the state with the fewest edits next
        priority_queue<state, vector<state>, greater<state>> explore;

        // Initial state, both indices at 0, 0 edits
        explore.push({0, 0, 0});
        min_edits[0][0] = 0;

        while (!explore.empty()) {
            state current = explore.top();
            explore.pop();

            int i = current.i;
            int j = current.j;
            int edits = current.edits;

            // If we've reached the end of both words, this is our answer
            if (i == n && j == m) return edits;

            // If we found a shorter path to this (i, j), skip
            if (edits > min_edits[i][j]) continue;

            // CASE 1: Match
            if (i < n && j < m && word1[i] == word2[j]) {
                if (edits < min_edits[i + 1][j + 1]) {
                    min_edits[i + 1][j + 1] = edits;
                    explore.push({i + 1, j + 1, edits});
                }
            } else {
                // CASE 2: Replace (Edit)
                if (i < n && j < m && edits + 1 < min_edits[i + 1][j + 1]) {
                    min_edits[i + 1][j + 1] = edits + 1;
                    explore.push({i + 1, j + 1, edits + 1});
                }
                // CASE 3: Delete from word1
                if (i < n && edits + 1 < min_edits[i + 1][j]) {
                    min_edits[i + 1][j] = edits + 1;
                    explore.push({i + 1, j, edits + 1});
                }
                // CASE 4: Insert into word1 (or delete from word2)
                if (j < m && edits + 1 < min_edits[i][j + 1]) {
                    min_edits[i][j + 1] = edits + 1;
                    explore.push({i, j + 1, edits + 1});
                }
            }
        }

        return 0;
    }
};