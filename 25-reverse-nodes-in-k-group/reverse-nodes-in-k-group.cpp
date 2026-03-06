class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (!curr) return head;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        curr = head;
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};