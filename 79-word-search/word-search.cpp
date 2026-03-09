class Solution {
public:
    bool search(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index == word.size()) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = search(board, i + 1, j, word, index + 1) ||
                     search(board, i - 1, j, word, index + 1) ||
                     search(board, i, j + 1, word, index + 1) ||
                     search(board, i, j - 1, word, index + 1);

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (search(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};