class Solution {
private:
    void solve(int idx, int target, vector<int> &path, set<vector<int>> &st, vector<int> candidates){
        // base case
        if(target==0){
            st.insert(path);
            return;
        }

        // out of bound
        if(idx>=candidates.size() || target<0) return;
        
        // include
        path.push_back(candidates[idx]);
        solve(idx+1,(target-candidates[idx]),path,st,candidates);
        path.pop_back();

        // exclude
        solve(idx+1,target,path,st,candidates);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // BRUTE FORCE
        set<vector<int>> st;
        vector<int> path;

        sort(candidates.begin(),candidates.end());
        solve(0,target,path,st,candidates);

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// TC : O(2^k*t*logn)
// SC : O(t*something) + O(N)