class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // BETTER
        sort(nums.begin(),nums.end());

        int n=nums.size();

        // edge case , when size is 1
        if(n==1) return nums[0];

        int count=1;
        int majority = n/2;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                count++;
                if(count > majority) return nums[i];
            }
            else{
                count=1;
            }
        }

        return -1;
    }
};

// TC : O(NlogN) + O(N)
// SC : O(1)