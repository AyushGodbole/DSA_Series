class Solution {
private:
    void solve(int idx, vector<int> temp, vector<vector<int>> &ans, vector<int> nums, int n){
        // base case
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        // exclude
        solve(idx+1,temp,ans,nums,n);

        // include
        temp.push_back(nums[idx]);
        solve(idx+1,temp,ans,nums,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // POWER SET - simply use include/exclude approach.
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,ans,nums,n);

        return ans;
    }
};

// TC : O(2^n*k)
// SC : O(k*x)