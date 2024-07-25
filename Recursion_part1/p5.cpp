class Solution {
private:
    void solve(int idx, vector<int> temp, set<vector<int>> &st, vector<int> nums, int n){
        // base case
        if(idx==n){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }

        // exclude
        solve(idx+1,temp,st,nums,n);

        // include
        temp.push_back(nums[idx]);
        solve(idx+1,temp,st,nums,n);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // BRUTE FORCE - POWER SET approach
        // using set for uniqueness
        int n = nums.size();
        set<vector<int>> st;
        vector<int> temp;
        solve(0,temp,st,nums,n);

        vector<vector<int>> ans(st.begin(),st.end());

        return ans;
    }
};

// TC : O(2^n*k)
// SC : O(k*x) + (x)