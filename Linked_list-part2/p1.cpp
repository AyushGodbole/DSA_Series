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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // better

        // storing each node(address) into map
        unordered_map<ListNode *,bool> visited;
        ListNode *temp = headA;
        while(temp!=NULL){
            visited[temp] = true;
            temp = temp->next;
        }

        temp = headB;
        while(temp!=NULL){
            if(visited[temp]) return temp;
            temp = temp->next;
        }

        return NULL;
    }
};

// TC : O(N+M)
// SC : O(N)