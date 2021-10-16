"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        
        visited = {}
        queue = deque([node])
        visited[node] = Node(node.val, [])
        while queue:
            adj = queue.popleft();
            for neighbor in adj.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = Node(neighbor.val, [])
                    queue.append(neighbor)
                
                visited[neighbor].neighbors.append(visited[adj])
        
        return visited[node]
