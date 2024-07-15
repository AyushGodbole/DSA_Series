class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // OPTIMAL - using stack

        // hello world

        unordered_map<int,int> mp;
        stack<int> st;
        int n=nums2.size();
        for(int i=n-1; i>=0; i--){
            int ele = nums2[i];
            // find next grater element
            while(!st.empty() && st.top()<=ele) st.pop();

            // check if find next greater or not
            int res = !st.empty() ? st.top() : -1;
            st.push(ele);
            mp[ele] = res;
        }

        vector<int> ans;
        for(auto ele:nums1){
            ans.push_back(mp[ele]);
        }

        return ans;
    }
};

// TC : O(n2) + O(n1)
// SC : O(n2) for stack , + O(n1) for map