class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // BRUTE FORCE

        // count frequency
        unordered_map<int,int> mp;
        for(auto ele : nums){
            mp[ele]++;
        }

        // check frequency greater than 1
        for(auto it : mp){
            if(it.second>1) return it.first;
        }

        return -1;
    }
};

// TC : O(n) + O(n)
// SC : O(n)