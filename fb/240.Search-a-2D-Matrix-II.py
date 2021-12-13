class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # start from the left bottom corner
        row = len(matrix) - 1
        col = 0
        
        while row >= 0 and col < len(matrix[0]):
            if matrix[row][col] > target:
                row -= 1
            elif matrix[row][col] < target:
                col += 1
            else: 
                return True
            
        return False
