class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void solve(int idx, string s, vector<string> &path, vector<vector<string>> &ans, int n){
        // base case
        if(idx==n){
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<n; i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,path,ans,n);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // APPROACH

        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        solve(0,s,path,ans,n);

        return ans;
    }
};

// TC : O(2^n*n)
// SC : O(2^n*n)