class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        auto curr = root;
        vector<string> results;
        string currString;

        /// Constructing our trie
        for (auto word : words) {
            for (char letter : word) {
                letter = letter - 'a';
                if (!curr->children[letter]) curr->children[letter] = new TrieNode;
                curr = curr->children[letter];
            }
            curr->isLeaf = true;
            curr = root;
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int index = board[i][j] - 'a';
                if (root->children[index]) {
                    string s = "";
                    s += board[i][j];
                    backtrack(board, i, j, results, root->children[index], s);
                }
            }
        }

        return results;
    }

private:
    class TrieNode {
    public:
        TrieNode* children[26];
        bool isLeaf;

        TrieNode(bool leaf = false) {
            isLeaf = leaf;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode;

    void backtrack(vector<vector<char>>& board, int i, int j, vector<string>& results, TrieNode* curr, string& currWord) {
        if (curr->isLeaf) {
            results.push_back(currWord);
            curr->isLeaf = false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int r = i + dr, c = j + dc;
            if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c] != '#') {
                int idx = board[r][c] - 'a';
                if (curr->children[idx]) {
                    currWord.push_back(board[r][c]);
                    backtrack(board, r, c, results, curr->children[idx], currWord);
                    currWord.pop_back();
                }
            }
        }
        board[i][j] = temp;
    }
};