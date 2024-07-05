class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // BRUTE FORCE

        // Generate all sub arrays

        int maxSum = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                maxSum = max(maxSum,sum);
            }
        }

        return maxSum;
    }
};

// TC : O(n*n)
// SC : O(1)