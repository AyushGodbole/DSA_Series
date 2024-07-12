class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // BETTER - calculating third by -(nums[i]+nums[j])

        int n=nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            set<int> hashMp;
            for(int j=i+1; j<n; j++){
                int third = -(nums[i]+nums[j]);
                // if third present in hashmap
                if(hashMp.find(third)!=hashMp.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashMp.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

// TC : O(N^2)
// SC : O(N)