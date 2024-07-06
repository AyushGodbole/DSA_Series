class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // OPTIMAL - using slow, fast logic of Linked List

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);

        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};

// TC : O(N) + O(N)
// SC : O(1)