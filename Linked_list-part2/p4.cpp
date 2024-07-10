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
    void reverseList(ListNode* &head) {
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(temp!=NULL){
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }

        head = prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // OPTIMAL
        if(head->next==NULL) return true;

        // 1. find middle of linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;

        // 2. reverse next of middle node
        ListNode* temp1 = head;
        ListNode* temp2 = middle->next;
        reverseList(temp2);

        // 3. check now
        while(temp2!=NULL){
            if(temp1->val != temp2->val){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};

// TC : O(N) + O(N/2)
// SC : O(1)