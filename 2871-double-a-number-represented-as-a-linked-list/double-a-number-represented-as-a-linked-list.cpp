/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        head = doubleIt_helper(head);
        
        if (head->val > 9) {
            int carry = head->val / 10;
            head->val %= 10;
            return new ListNode(carry, head);
        }

        return head;
    }

private:
    ListNode* doubleIt_helper(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* deepest_node = doubleIt_helper(head->next);
        
        head->val *= 2;
        
        if (deepest_node != nullptr && deepest_node->val > 9) {
            int carry = deepest_node->val / 10;
            deepest_node->val %= 10;
            head->val += carry;
        }
        
        return head;
    }
};