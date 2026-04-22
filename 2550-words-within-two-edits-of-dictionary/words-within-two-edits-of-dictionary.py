class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        results = []
        
        for query in queries:
            for word in dictionary:
                # Count positional differences
                diff = 0
                for i in range(len(query)):
                    if query[i] != word[i]:
                        diff += 1
                    if diff > 2:
                        break
                
                # If a match is found, add query and move to next query
                if diff <= 2:
                    results.append(query)
                    break

        return results