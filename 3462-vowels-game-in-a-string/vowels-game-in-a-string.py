class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return len([char for char in s if char in 'aeiou']) > 0
        