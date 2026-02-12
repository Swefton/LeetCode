class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]:
        root = {}
        weight = {}

        def find(i):
            if i not in root:
                root[i] = i
                weight[i] = 1.0
            if root[i] != i:
                original_parent = root[i]
                root[i] = find(original_parent)
                weight[i] *= weight[original_parent]
            return root[i]

        def union(i, j, value):
            root_i, root_j = find(i), find(j)
            if root_i != root_j:
                root[root_i] = root_j
                weight[root_i] = value * weight[j] / weight[i]

        for (a, b), val in zip(equations, values):
            union(a, b, val)

        results = []
        for a, b in queries:
            if a not in root or b not in root or find(a) != find(b):
                results.append(-1.0)
            else:
                results.append(weight[a] / weight[b])
        
        return results