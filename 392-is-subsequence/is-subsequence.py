class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s == "":
            return True

        index = 0

        for char in t:
            if char == s[index]:
                index += 1
            if index == len(s):
                return True

        return False
