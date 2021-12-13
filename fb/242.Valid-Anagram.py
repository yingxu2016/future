class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        seen = set()
        for ch in s:
            if ch not in seen and s.count(ch) != t.count(ch):
                return False
            seen.add(ch)
        return True
    
 
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        counter = [0] * 26
        for i in range(len(s)):
            counter[ord(s[i]) - ord('a')] += 1
            counter[ord(t[i]) - ord('a')] -= 1
        
        for c in counter:
            if c != 0:
                return False
        return True
