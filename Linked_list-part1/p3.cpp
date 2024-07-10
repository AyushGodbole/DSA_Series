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

        // BRUTE FORCE

        // base cases
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                // create node
                ListNode* newNode = new ListNode(temp1->val);

                if(newHead==NULL && newTail==NULL){
                    newHead = newNode;
                    newTail = newNode;
                }
                else{
                    newTail->next = newNode;
                    newTail = newNode;
                }
                temp1 = temp1->next;
            }
            else{
                // create node
                ListNode* newNode = new ListNode(temp2->val);

                if(newHead==NULL && newTail==NULL){
                    newHead = newNode;
                    newTail = newNode;
                }
                else{
                    newTail->next = newNode;
                    newTail = newNode;
                }
                temp2 = temp2->next;
            }
        }

        // temp1 left
        while(temp1!=NULL){
            ListNode* newNode = new ListNode(temp1->val);
            newTail->next = newNode;
            newTail = newNode;
            temp1 = temp1->next;
        }

        // temp1 left
        while(temp2!=NULL){
            ListNode* newNode = new ListNode(temp2->val);
            newTail->next = newNode;
            newTail = newNode;
            temp2 = temp2->next;
        }

        return newHead;
    }
};

// TC : O(N1+N2)
// SC : O(N1+N2)