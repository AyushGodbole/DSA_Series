class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // BRUTE FORCE

        // storing elements into set , then replacing in main array
        set<int> st;
        for(auto ele : nums){
            st.insert(ele);
        }

        int i=0;
        int len=0;
        for(auto ele : st){
            nums[i++] = ele;
            len++;
        }

        return len;
    }
};

// TC : O(N) + O(N)
// SC : O(1)