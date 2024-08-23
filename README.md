# LeetCode Solutions
These are my leetcode solutions.

## Proudest Solves

- [Double a Number Represented as a Linked List](2871-double-a-number-represented-as-a-linked-list)
   - **Description:** Given a number where each digit is represented by a node in a singly linked list, double the number.
   - **Solution:** This problem is best solved when the deepest node is processed first, to do so I decided I require a stack. To optimize memory I decided to use a recursive solution so no new memory is allocated to creating a stack.
   - PS: This is my friend's solution bellow, I think it's pretty cool how [they](https://github.com/spaceybread) manipulated a [vulnerability](https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2020-10735) in Python for their solve
   ```python
      class Solution:
        def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
           import sys
           sys.set_int_max_str_digits(0)
           build = head.val
           node = head
           while node.next != None:
               node = node.next
               build = build*10 + node.val
               
           build = str(build << 1)
           newHead = ListNode(int(build[0]))
           curr = newHead
           for i in range(1, len(build)):
               curr.next = ListNode(int(build[i]))
               curr = curr.next
           
           return newHead
     ```

## Unsolved Questions

### Problem 1: [Strange Printer](https://leetcode.com/problems/strange-printer/description/)

**Description:**

You are given a string `s` and a strange printer that operates with the following two special properties:

1. The printer can only print a sequence of the same character at a time.
2. In each turn, the printer can start printing new characters at any position in the string and will overwrite the existing characters.

Your task is to return the minimum number of turns the printer needs to print the entire string `s`.

**Examples:**

- **Example 1:**
  - **Input:** `s = "aaabbb"`
  - **Output:** `2`
  - **Explanation:** Print `"aaa"` first, then print `"bbb"`.

- **Example 2:**
  - **Input:** `s = "aba"`
  - **Output:** `2`
  - **Explanation:** Print `"aaa"` first, then print `"b"` at the second position, which will overwrite the existing character `'a'`.



<!--

- **Problem 1:** [Problem Name](link_to_problem)
   - **Description:** Brief description of the problem.

--!>

