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
    ListNode *detectCycle(ListNode *head) {
        // OPTIMAL - using slow,fast concept
        if(head==NULL || head->next==NULL) return NULL;
        
        // 1. slow moves by 1, fast moves by 2 and first collision occurs
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                //1st collision occured
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};

// TC : O(N)
// SC : O(1)