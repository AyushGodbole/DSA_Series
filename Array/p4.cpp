class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // OPTIMAL - Kadanes Algo

        // discard -ve sum 

        int maxSum = INT_MIN;
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
        }

        return maxSum;
    }
};

// TC : O(n)
// SC : O(1)