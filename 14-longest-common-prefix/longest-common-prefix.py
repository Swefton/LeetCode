class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        prefix = ""
        i = 0

        while True:
            if i >= len(strs[0]):
                break
            
            current_char = strs[0][i]
            for s in strs:
                if i >= len(s) or s[i] != current_char:
                    return prefix
            
            prefix += current_char
            i += 1
        
        return prefix
