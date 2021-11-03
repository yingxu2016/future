class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if not c in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isEndOfWord = True
        

    def search(self, word: str) -> bool:
        def dfs(word, node):
            for i, c in enumerate(word):
                if c in node.children:
                    node = node.children[c]
                else:
                    if c == ".":
                        for n in node.children.values():
                            if dfs(word[i+1:], n):
                                return True
                    return False
            
            return node.isEndOfWord
        return dfs(word, self.root)
            

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
