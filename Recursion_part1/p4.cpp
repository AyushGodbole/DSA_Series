class Solution {
  private:
    void solve(int idx, int sum, vector<int> arr, int n, vector<int> &ans){
        // base case
        if(idx==n){
            ans.push_back(sum);
            return;
        }
        
        // exclude the number
        solve(idx+1,sum,arr,n,ans);
        
        // include the number
        solve(idx+1,sum+arr[idx],arr,n,ans);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // MY own Logical code
        vector<int> ans;
        int sum=0;
        solve(0,sum,arr,n,ans);
        return ans;
    }
};

// TC : O(2^n * k)
// SC : O(n*k)