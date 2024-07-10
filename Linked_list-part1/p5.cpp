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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        // carry
        int carry=0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL || temp2!=NULL || carry){
            int sum = 0;
            // add l1
            if(temp1!=NULL){
                sum+=temp1->val;
                temp1=temp1->next;
            }

            // add l2
            if(temp2!=NULL){
                sum+=temp2->val;
                temp2=temp2->next;
            }

            // add carry
            sum+=carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = newNode;
        }

        return dummy->next;
    }
};

// TC : O(N1+N2+carry)
// SC : O(N1+N2)