class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for row in board:
            valid_row = [i for i in row if i.isdigit()]
            if len(set(valid_row)) != len(valid_row):
                return False
        
        for i in range(len(board)):
            valid_col = [digit for digit in [row[i] for row in board] if digit.isdigit()]
            if len(set(valid_col)) != len(valid_col):
                return False


        for x in range(1, len(board), 3):
            for y in range(1, len(board), 3):
                valid_square = set()
                for i in [-1, 0, 1]:
                    for j in [-1, 0, 1]:
                        char = board[x+i][y+j]

                        if not char.isdigit():
                            continue
                        elif char in valid_square:
                            return False
                        else:
                            valid_square.add(char)

        return True

