class Solution {
private:
    void solve(int idx, int target, vector<int> &path, vector<vector<int>> &ans, vector<int> nums, int n){
        // base case
        if(target==0){
            ans.push_back(path);
            return;
        }

        // traverse elements
        for(int i=idx; i<n; i++){
            if(i>idx && nums[i-1]==nums[i]) continue;
            if(target<nums[i]) break;

            path.push_back(nums[i]);
            solve(i+1,(target-nums[i]),path,ans,nums,n);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // OPTIMAL - same as previous , just avoid picking previous same element.

        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        solve(0,target,path,ans,candidates,n);

        return ans;
    }
};

// TC : O(2^n * k)
// SC : O(k*x)