class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // BETTER
        int i=0;
        int j=0;

        vector<int> ans;

        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // nums1 left
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        // nums2 left
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        // copying ans to nums1
        for(int k=0; k<m+n; k++){
            nums1[k] = ans[k];
        }
    }
};

// TC : O(N+M) + O(M) + O(N)
// SC : O(N+M)