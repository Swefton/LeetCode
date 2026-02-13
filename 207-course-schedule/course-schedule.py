class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for a, b in prerequisites:
            graph[b].append(a)
        
        visited = set()
        path = set()

        def topo_sort(node):
            if node in path:
                return True
            if node in visited:
                return False
            
            path.add(node)
            for connection in graph[node]:
                if topo_sort(connection):
                    return True
            
            path.remove(node)
            visited.add(node)
            return False
        
        for i in range(numCourses):
            if topo_sort(i):
                return False

        return True