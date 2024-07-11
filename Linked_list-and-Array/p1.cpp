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
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // OPTIMAL

        if(head==NULL || head->next==NULL) return head;
        int n = getLength(head);
        k = k%n;

        // 1. go to last node
        ListNode* temp = head;
        while(temp->next!=NULL) temp = temp->next;

        // 2. make last node , points to first node i.e make circular node
        temp->next = head;

        // 3. got to (n-k)th node
        temp = head;
        int j = (n-k);
        for(int i=1; i<j; i++) temp = temp->next;

        // 4. update head
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

// TC : O(N) + O(N-k)
// SC : O(1)