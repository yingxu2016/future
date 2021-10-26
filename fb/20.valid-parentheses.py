class Solution:
    def isValid(self, s: str) -> bool:
        charMap = {"(":")", "[":"]", "{":"}"}
        charSet = set(["(", "[", "{"])
        stack = []
        
        for char in s:
            if char in charSet:
                stack.append(char)
            elif stack and char == charMap[stack[-1]]:
                stack.pop()
            else:
                return False
        return stack == []
