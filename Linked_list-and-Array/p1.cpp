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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int length = 0;
        while(temp!=NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // BRUTE FORCE- rotating one by one
        if(head==NULL || head->next==NULL) return head;

        int len = getLength(head);
        k = k%len;

        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(temp->next!=NULL && k){
            temp = temp->next;
            prev = curr;
            curr = temp;

            // check if last node , make it head node
            if(temp->next==NULL){
                prev->next = NULL;
                temp->next = head;
                head = temp;
                prev = NULL;
                k--;
            }
        }

        return head;
    }
};

// TC : O(k*n)
// SC : O(1)