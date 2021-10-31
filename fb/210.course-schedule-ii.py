class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj_list = defaultdict(list)
        indegree = {}
        
        for dest, src in prerequisites:
            adj_list[src].append(dest)
            indegree[dest] = indegree.get(dest, 0) + 1
        
        topolocial_sorted_set = []
        zero_indegree_queue = deque([v for v in range(numCourses) if v not in indegree])
        
        while zero_indegree_queue:
            vertex = zero_indegree_queue.popleft()
            topolocial_sorted_set.append(vertex)
            if adj_list.get(vertex):
                for neighbor in adj_list[vertex]:
                    indegree[neighbor] -= 1
                    
                    if indegree[neighbor] == 0:
                        zero_indegree_queue.append(neighbor)
        
        return topolocial_sorted_set if len(topolocial_sorted_set) == numCourses else []
