class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // OPTIMAL :

        // 1. find break point
        int indi = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                indi = i;
                break;
            }
        }

        // if next permutation not found
        if(indi==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // 2. find next grater element than nums[indi]
        for(int i=n-1; i>=indi; i--){
            if(nums[i]>nums[indi]){
                swap(nums[i],nums[indi]);
                break;
            }
        }

        // 3. sort from next of indi
        reverse(nums.begin()+indi+1,nums.end());
    }
};

// TC : O(n) + O(n)
// SC : O(1)