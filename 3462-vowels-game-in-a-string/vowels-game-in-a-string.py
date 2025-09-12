class Solution:
    def doesAliceWin(self, s: str) -> bool:
        "aa"
        return len([char for char in s if char in 'aeiou']) > 0
        