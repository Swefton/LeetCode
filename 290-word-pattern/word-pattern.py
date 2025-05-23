class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()

        if len(pattern) != len(s):
            return False

        s_count = {}
        pattern_count = {}

        for i in range(len(s)):
            if s[i] not in s_count:
                s_count[s[i]] = i

            if pattern[i] not in pattern_count:
                pattern_count[pattern[i]] = i
            
            if s_count[s[i]] != pattern_count[pattern[i]]:
                return False

        return True