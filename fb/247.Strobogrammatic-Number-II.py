class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        return self.helper(n, n)
    
    def helper(self, n, m):
        if n == 0:
            return [""]
        if n == 1:
            return ["0", "1", "8"]
        
        preResult = self.helper(n-2, m)
        curResult = []
        
        for i in preResult:
            if n != m:
                curResult.append("0" + i + "0")
            curResult.append("1" + i + "1")
            curResult.append("6" + i + "9")
            curResult.append("8" + i + "8")
            curResult.append("9" + i + "6")
        return curResult
