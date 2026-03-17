class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // row - col
        vector<bool> diag2(2 * n, false); // row + col

        backtrack(0, n, board, results, cols, diag1, diag2);
        return results;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& results,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;

            backtrack(row + 1, n, board, results, cols, diag1, diag2);

            board[row][col] = '.';
            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }
};