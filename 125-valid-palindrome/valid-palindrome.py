class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(char.lower() for char in s if char.isalnum())
        return True if s == s[::-1] else False