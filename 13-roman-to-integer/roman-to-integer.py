class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0
        
        vals = {
                'I': 1,
                'V': 5,
                'X': 10,
                'L': 50,
                'C': 100,
                'D': 500,
                'M': 1000
                }
        
        i, char = 0, s[0]
        while i < len(s):
            if i < len(s)-1 and vals[char] < vals[s[i+1]]:
                result += vals[s[i+1]] - vals[char]
                i += 2
            else:
                result += vals[s[i]]
                i += 1
            
            if i < len(s):
                char = s[i]

        return result
