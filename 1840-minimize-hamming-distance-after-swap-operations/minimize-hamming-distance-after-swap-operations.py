class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        adj = defaultdict(list)
        for u, v in allowedSwaps:
            adj[u].append(v)
            adj[v].append(u)
            
        visited = [False] * n
        total_matches = 0
        
        for i in range(n):
            if not visited[i]:
                # Identify all indices in the connected component using DFS
                component_indices = []
                stack = [i]
                visited[i] = True
                while stack:
                    curr = stack.pop()
                    component_indices.append(curr)
                    for neighbor in adj[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            stack.append(neighbor)
                
                # Count frequencies of values at these indices in both arrays
                source_vals = Counter(source[idx] for idx in component_indices)
                target_vals = Counter(target[idx] for idx in component_indices)
                
                # Calculate how many values can be correctly positioned
                for val, count in source_vals.items():
                    total_matches += min(count, target_vals[val])
                    
        return n - total_matches