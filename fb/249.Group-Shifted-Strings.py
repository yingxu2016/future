class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        hashMap = defaultdict(list)
        for s in strings:
            hashValue = ""
            for c in s:
                hashValue += str((ord(c) + 26 - ord(s[0])) % 26) + ","
            hashMap[hashValue].append(s)
            
        return [v for v in hashMap.values()]
