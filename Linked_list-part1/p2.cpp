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
    ListNode* middleNode(ListNode* head) {
        // BRUTE FORCE

        // 1. count length of LL
        int n=0;
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }

        // 2. calculate n/2+1
        int count = n/2 + 1;
        temp = head;

        while(count>1){
            temp=temp->next;
            count--;
        }

        return temp;
    }
};

// TC : O(N) + O(N/2)
// SC : O(1)