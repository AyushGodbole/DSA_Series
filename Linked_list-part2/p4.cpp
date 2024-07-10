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
    bool isPalindrome(ListNode* head) {
        // BRUTE FORCE - storing in array and then checking
        vector<int> nums;
        ListNode* temp = head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            if(nums[start]!=nums[end]){
                return false;
            }
            else{
                start++;
                end--;
            }
        }

        return true;
    }
};

// TC : O(N)
// SC : O(N)