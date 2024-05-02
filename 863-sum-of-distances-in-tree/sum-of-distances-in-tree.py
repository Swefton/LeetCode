class Solution(object):
    def sumOfDistancesInTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        adj_list = [[] for i in range(n)]
        for edge in edges:
            src, dest = edge
            adj_list[src].append(dest)
            adj_list[dest].append(src)
        
        count = [1] * n  # Count of nodes in the subtree rooted at each node
        distance_sum = [0] * n  # Sum of distances from each node to all other nodes
        
        def dfs(node, parent):
            for neighbor in adj_list[node]:
                if neighbor != parent:
                    dfs(neighbor, node)
                    count[node] += count[neighbor]
                    distance_sum[node] += distance_sum[neighbor] + count[neighbor]

        def dfs2(node, parent):
            for neighbor in adj_list[node]:
                if neighbor != parent:
                    distance_sum[neighbor] = distance_sum[node] - count[neighbor] + (n - count[neighbor])
                    dfs2(neighbor, node)
        
        dfs(0, -1)
        
        dfs2(0, -1)
        
        return distance_sum
