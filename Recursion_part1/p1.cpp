class Solution {
private:
    void solve(int idx, int target, vector<int> &path, vector<vector<int>> &ans, vector<int> candidates){
        // base case
        if(target==0){
            ans.push_back(path);
            return;
        }

        // out of bound
        if(idx>=candidates.size() || target<0) return;
        
        // include
        path.push_back(candidates[idx]);
        solve(idx,(target-candidates[idx]),path,ans,candidates);
        path.pop_back();

        // exclude
        solve(idx+1,target,path,ans,candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(0,target,path,ans,candidates);

        return ans;
    }
};

// TC : (2^t * k)
// SC : (t*something)