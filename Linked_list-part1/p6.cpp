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
    void deleteNode(ListNode* node) {
        // Better 
        ListNode* temp = node;
        ListNode* nextNode = node->next;

        while(nextNode->next!=NULL){
            temp->val = nextNode->val;
            temp = temp->next;
            nextNode = nextNode->next;
        }

        temp->val = nextNode->val;
        temp->next = NULL;
    }
};

// TC : O(no of nodes next to delete node)