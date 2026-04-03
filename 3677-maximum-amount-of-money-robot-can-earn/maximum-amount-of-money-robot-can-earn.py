class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m = len(coins)
        n = len(coins[0])
        
        dp = [[[-float('inf')] * 3 for _ in range(n)] for _ in range(m)]

        # 4 -1 8 2
        # (4, 0, 0) (3, -1, 0) (11, 7, 8)

        # initialize base case
        dp[0][0][0] = coins[0][0]
        dp[0][0][1] = max(0, coins[0][0])
        dp[0][0][2] = max(0, coins[0][0])

        # First Column (i > 0, j = 0)
        for i in range(1, m):
            dp[i][0][0] = dp[i-1][0][0] + coins[i][0]
            dp[i][0][1] = max(dp[i-1][0][1] + coins[i][0], dp[i-1][0][0])
            dp[i][0][2] = max(dp[i-1][0][2] + coins[i][0], dp[i-1][0][1])

        # First Row (i = 0, j > 0)
        for j in range(1, n):
            dp[0][j][0] = dp[0][j-1][0] + coins[0][j]
            dp[0][j][1] = max(dp[0][j-1][1] + coins[0][j], dp[0][j-1][0])
            dp[0][j][2] = max(dp[0][j-1][2] + coins[0][j], dp[0][j-1][1])

        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + coins[i][j]

                dp[i][j][1] = max(
                    max(dp[i-1][j][1], dp[i][j-1][1]) + coins[i][j],
                    max(dp[i-1][j][0], dp[i][j-1][0])
                )

                dp[i][j][2] = max(
                    max(dp[i-1][j][2], dp[i][j-1][2]) + coins[i][j],
                    max(dp[i-1][j][1], dp[i][j-1][1])
                )

        return max(dp[m-1][n-1])