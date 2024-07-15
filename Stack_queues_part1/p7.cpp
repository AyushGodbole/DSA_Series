class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // BRUTE FORCE
        vector<int> ans;

        // 1. repeat the array
        int n=nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            arr.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            arr.push_back(nums[i]);
        }


        // 2. find next greater
        int n2 = arr.size();
        for(int i=0; i<n; i++){
            int ele=nums[i];
            int maxi=INT_MIN;
            for(int j=i+1; j<n2; j++){
                if(arr[j]>ele){
                    maxi = max(maxi,arr[j]);
                    break;
                }
            }
            if(maxi==INT_MIN) maxi=-1;
            ans.push_back(maxi);
        }

        return ans;
    }
};

// TC : O(n * (2n))
// SC : O(2n)