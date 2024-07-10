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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Optimal - using slow, fast

        ListNode* fast = head;
        ListNode* slow = head;

        // 1. move fast by 1 for n iterations
        for (int i = 1; i <= n; i++) {
            fast = fast->next;
        }

        // Edge case: if fast is nullptr, it means we need to remove the head node
        if (fast == NULL) {
            ListNode* newHead = head->next;
            delete head; // Free the memory
            return newHead;
        }

        // 2. move slow, fast by 1 until fast->next is nullptr
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory

        return head;
    }
};

// TC: O(N)
// SC: O(1)
