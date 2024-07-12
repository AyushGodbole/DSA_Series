class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // BRUTE FORCE - checking each 

        int n = nums.size();
        // set to store unique elements
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());

                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// TC : O(N^3)
// SC : O(N)