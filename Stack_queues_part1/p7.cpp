class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // OPTIMAL

        stack<int> st;
        vector<int> ans(nums.size(), -1); // Initialize answer vector with -1
        int n = nums.size();
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            int ele = nums[i % n];
            // Get next greater element
            while (!st.empty() && st.top() <= ele) {
                st.pop();
            }

            // If i < n, we are in the first pass and need to fill the answer
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }
            // Push current element to stack
            st.push(ele);
        }

        return ans;
    }
};

// TC : O(2n)
// SC : O(n)