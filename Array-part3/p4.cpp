class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // BRUTE FORCE

        unordered_map<int,int> mp;
        for(auto ele:nums){
            mp[ele]++;
        }

        vector<int> ans;
        int n=nums.size();
        int majority=n/3;
        for(auto it:mp){
            if(it.second > majority) ans.push_back(it.first);
        }

        return ans;
    }
};

// TC : O(N) + O(N)
// SC : O(N)