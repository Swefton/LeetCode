class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left, curr, best = 0, set(), 0

        for right in range(len(s)):
            while s[right] in curr:
                curr.remove(s[left])
                left += 1
            curr.add(s[right])
            best = max(best, right - left + 1)

        return best
