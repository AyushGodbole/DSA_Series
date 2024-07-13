class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // BRUTE FORCE

        unordered_map<int,int> mp;
        for(auto ele:nums){
            mp[ele]++;
        }

        int n=nums.size();
        int majority=n/2;
        for(auto it:mp){
            if(it.second > majority) return it.first;
        }

        return -1;
    }
};

// TC : O(N) + O(N)
// SC : O(N)