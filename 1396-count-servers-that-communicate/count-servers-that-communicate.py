class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        communicable_servers_count = 0
        col_server_counts = [0] * len(grid[0])
        single_server_in_row = [-1] * len(grid)

        for i in range(len(grid)):
            server_count_in_row = 0
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    server_count_in_row += 1
                    col_server_counts[j] += 1
                    single_server_in_row[i] = j

            if server_count_in_row > 1:
                communicable_servers_count += server_count_in_row
                single_server_in_row[i] = -1

        for i in range(len(grid)):
            if single_server_in_row[i] != -1:
                j = single_server_in_row[i]
                if col_server_counts[j] > 1:
                    communicable_servers_count += 1

        return communicable_servers_count
