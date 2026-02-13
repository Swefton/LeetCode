class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj = defaultdict(list)
        in_degree = [0] * numCourses
        
        for dest, src in prerequisites:
            adj[src].append(dest)
            in_degree[dest] += 1
            
        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        
        courses_taken = 0
        
        while queue:
            current = queue.popleft()
            courses_taken += 1
            
            for neighbor in adj[current]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
                    
        return courses_taken == numCourses