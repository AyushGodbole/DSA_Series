class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // if nums[i]==0 , set count=0;

        int maxi = 0;
        int count=0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count = 0;
            }
            else{
                count++;
                maxi = max(maxi,count);
            }
        }

        return maxi;
    }
};

// TC : O(N)
// SC : O(1)