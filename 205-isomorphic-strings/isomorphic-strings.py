class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_count = {}
        t_count = {}

        for i in range(len(s)):
            if s[i] not in s_count:
                s_count[s[i]] = i

            if t[i] not in t_count:
                t_count[t[i]] = i
            
            if s_count[s[i]] != t_count[t[i]]:
                return False

        return True