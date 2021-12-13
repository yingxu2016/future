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
