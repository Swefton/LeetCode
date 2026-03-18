class Solution {
public:
    int totalNQueens(int n) {
        int uniqueSetups = 0;

        set colsUsed;
        set diagsUsed;
        set antidiagsUsed;

        backtracking(n, 0, uniqueSetups, colsUsed, diagsUsed, antidiagsUsed);

        return uniqueSetups;
    }

private:
    using set = unordered_set<int>;
    void backtracking(int n, int row, int &setups, set &colsUsed, set &diagsUsed, set &antidiagsUsed) {
        if (row == n) {
            setups++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            int diag = row - col;
            int antiDiag = row + col;

            if (colsUsed.contains(col) || diagsUsed.contains(diag) || antidiagsUsed.contains(antiDiag)) continue;

            colsUsed.insert(col);
            diagsUsed.insert(diag);
            antidiagsUsed.insert(antiDiag);

            backtracking(n, row + 1, setups, colsUsed, diagsUsed, antidiagsUsed);

            colsUsed.erase(col);
            diagsUsed.erase(diag);
            antidiagsUsed.erase(antiDiag);
        }
    }
};