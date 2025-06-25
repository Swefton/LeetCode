class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()

        pairs = {
            ')' : '(',
            '}' : '{',
            ']' : '['
        }

        opening = set(pairs.values())

        for i in s:
            if i in opening:
                stack.append(i)

            else:
                if not stack or stack.pop() != pairs[i]:
                    return False

        return True if len(stack) == 0 else False
        