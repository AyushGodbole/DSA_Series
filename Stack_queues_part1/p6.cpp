class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // BRUTE FORCE - checking each

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int ele=nums1[i];
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j]==ele){
                    int maxi=-1;
                    for(int k=j+1; k<nums2.size(); k++){
                        if(nums2[k]>ele){
                            maxi = max(maxi,nums2[k]);
                            break;
                        }
                    }
                    ans.push_back(maxi);
                }
            }
        }

        return ans;
    }
};

// TC : O(n1 * (n2*n2))
// SC : O(1)