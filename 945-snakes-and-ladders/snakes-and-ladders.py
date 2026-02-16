class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        flatten = []
        reverse = False
        
        for i in range(n - 1, -1, -1):
            flatten.extend(board[i][::-1] if reverse else board[i])
            reverse = not reverse
        
        queue = deque([(0, 0)]) 
        visited = {0}
        target = len(flatten) - 1

        while queue:
            curr_pos, moves = queue.popleft()
            
            if curr_pos == target:
                return moves
            
            for i in range(1, 7):
                next_pos = curr_pos + i
                if next_pos > target:
                    break
                
                destination = flatten[next_pos] - 1 if flatten[next_pos] != -1 else next_pos
                
                if destination not in visited:
                    visited.add(destination)
                    queue.append((destination, moves + 1))
        
        return -1