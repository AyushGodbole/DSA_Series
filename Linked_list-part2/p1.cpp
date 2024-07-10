/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int findLen(ListNode* head){
        int len=0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // OPTIMAL

        // 1. find lengths
        int len1 = findLen(headA);
        int len2 = findLen(headB);

        // 2. find difference
        int diff = abs(len1-len2);
        ListNode* temp1=NULL;
        ListNode* temp2 = NULL;
        // temp1 points to larger length list
        if(len1>len2){
            temp1 = headA;
            temp2 = headB;
        }
        else{
            temp1 = headB;
            temp2 = headA;
        }

        // 3. move larger list by diff
        while(diff--){
            temp1 = temp1->next;
        }

        // 4. now traverse both by 1
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;
    }
};

// TC : O(N1) + O(N2) + O(Diff)
// SC : O(1)