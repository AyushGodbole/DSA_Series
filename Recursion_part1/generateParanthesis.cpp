class Solution {
private:
    void solve(string temp, int open, int close, vector<string> &ans){
        // base case
        if(open==0 && close==0){
            ans.push_back(temp);
            return;
        }

        if(open>0){
            solve(temp+'(',open-1,close,ans);
        }
        if(close>open){
            solve(temp+')',open,close-1,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // APPROACH

        int closeCount = n;
        int openCount = n;
        string temp = "";
        vector<string> ans;
        solve(temp,openCount,closeCount,ans);
        return ans;
    }
};

// TC : O(2^n * k)
// SC : O(k*x)