class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return sum([s.count(c) for c in 'aeiou']) > 0
        