# read solution, good explanation

class UnionFind:
    def __init__(self, n):
        self.parent = [node for node in range(n)]
        self.rank = [1]*n
        
    # def find(self, A):
    #     if self.parent[A] != A:
    #         self.parent[A] = self.find(self.parent[A])
    #     return A
    
    def find(self, A):
        root = A
        while root != self.parent[root]:
            root = self.parent[root]
            
        while A != root:
            old_root = self.parent[A]
            self.parent[A] = root
            A = old_root
        return root
    
    def union(self, A, B):
        rootA = self.find(A)
        rootB = self.find(B)
        if rootA == rootB:
            return False
            
        if self.rank[rootA] < self.rank[rootB]:
            self.parent[rootA] = rootB
            self.rank[rootB] += self.rank[rootA]
        else:
            self.parent[rootB] = rootA
            self.rank[rootA] += self.rank[rootB]
        return True
        
    
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n-1:
            return False
        unionFind = UnionFind(n)
        for A, B in edges:
            if not unionFind.union(A, B):
                return False
        return True
