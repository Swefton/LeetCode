class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        ordered = list()
        graph = defaultdict(list)
        degree = [0] * numCourses

        for dest, src in prerequisites:
            graph[src].append(dest)
            degree[dest] += 1
        
        queue = deque([i for i in range(numCourses) if degree[i] == 0])

        while queue:
            top = queue.popleft()
            ordered.append(top)
            for next_node in graph[top]:
                degree[next_node] -= 1
                if degree[next_node] == 0:
                    queue.append(next_node)
        
        return ordered if sum(degree) == 0 else []
                
        