class Solution {
private:
    void solve(int idx, vector<int> &temp, vector<vector<int>> &ans, vector<int> nums, int n){
        ans.push_back(temp);

        for(int i=idx; i<n; i++){
            // avoid duplicate at same level
            if(i>idx && nums[i-1]==nums[i]) continue;
            
            // include
            temp.push_back(nums[i]);
            solve(i+1,temp,ans,nums,n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // OPTIMAL - avoid picking duplicate at same level
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,temp,ans,nums,n);

        return ans;
    }
};

// TC : O(2^n * n)
// SC : O(2^n * k)