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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // OPTIMAL - in-place

        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        // 1. l1 always points to smaller value
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        if(list1->val <= list2->val){
            l1 = list1;
            l2 = list2;
        }
        else{
            l1 = list2;
            l2 = list1;
        }

        cout<<l1->val<<" "<<l2->val;

        ListNode* res = l1;

        while(l1!=NULL && l2!=NULL){

            // 2. until l1->val <= l2->val , move l1
            ListNode* temp = NULL;
            while(l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }

            // 3. update links
            temp->next = l2;
            swap(l1,l2);
        }

        return res;
    }
};

// TC : O(N1+N2)
// SC : O(1)