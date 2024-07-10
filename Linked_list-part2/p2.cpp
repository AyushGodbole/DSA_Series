/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // OPTIMAL - using slow,fast concept
        if(head==NULL || head->next==NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        // slow moves by 1 , fast moves by 2
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }

        return false;
    }
};

// TC : O(N)
// SC : O(1)