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
private:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Calculate length
        int len = getLength(head);
        int node_to_delete = len - n + 1;

        // Edge case: if the head is the node to delete
        if (node_to_delete == 1) {
            ListNode* newHead = head->next;
            delete head; // Free the memory
            return newHead;
        }

        ListNode* temp = head;
        ListNode* prev = nullptr;
        int pos = 1;

        while (temp != nullptr) {
            if (pos == node_to_delete) {
                ListNode* next_node = temp->next;
                prev->next = next_node;
                delete temp; // Free the memory
                break;
            }

            pos++;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

// TC : O(N) + O(Len-N+1)
// SC : O(1)
