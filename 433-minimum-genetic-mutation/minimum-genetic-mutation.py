class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:

        def validMutation(gene1, gene2):
            count = 0
            for i in range(len(gene1)):
                if gene1[i] != gene2[i]:
                    count += 1

                if count > 1:
                    return False

            return True

        queue = deque([(startGene, 0)])
        visited = set()

        while queue:
            curr, steps = queue.popleft()
            if curr in visited:
                continue

            if curr == endGene:
                return steps

            queue.extend((i, steps + 1) for i in bank if validMutation(curr, i))

            visited.add(curr)
        
        return -1


