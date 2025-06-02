class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        copy = [row[:] for row in board]

        for y in range(len(board)):
            for x in range(len(board[0])):
                count = 0

                for k in range(y - 1, y + 2):
                    for l in range(x - 1, x + 2):
                        if (k != y or l != x) and 0 <= k < len(board) and 0 <= l < len(board[0]):
                            count += copy[k][l]
                
                if copy[y][x] == 0:
                    if count == 3:
                        board[y][x] = 1
                else:
                    if count < 2 or count > 3:
                        board[y][x] = 0
                    else:
                        board[y][x] = 1

        return
        