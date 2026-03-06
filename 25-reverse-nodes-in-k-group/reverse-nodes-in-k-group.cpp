class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Check if there are at least k nodes left
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head; // Less than k nodes, leave as is
            curr = curr->next;
        }

        // 2. Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Recursion: The 'head' is now the end of the reversed group
        // Point its 'next' to the result of the next k-group
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // 'prev' is the new head of this reversed segment
        return prev;
    }
};