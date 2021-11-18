class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows = len(matrix)
        columns = len(matrix[0])
        maxSide = 0
        dp = [[0] * (columns+1) for i in range(rows+1)]
        
        for i in range(1, rows+1):
            for j in range(1, columns+1):
                if matrix[i-1][j-1] == '1':
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    maxSide = max(maxSide, dp[i][j])
                    
        return maxSide * maxSide
