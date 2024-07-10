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
    bool hasCycle(ListNode *head) {
        // BRUTE FORCE - using map (hashing)

        unordered_map<ListNode*,bool> visited;
        ListNode* temp = head;

        while(temp!=NULL){
            // check if visited
            if(visited[temp]) return true;
            else{
                visited[temp] = true;
                temp = temp->next;
            }
        }

        return false;
    }
};

// TC : O(N)
// SC : O(N)