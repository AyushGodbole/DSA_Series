class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // OPTIMAL - updation of Moore's Algo

        int n=nums.size();

        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;

        for(int i=0; i<n; i++){
            if(count1==0 && nums[i]!=ele2){
                count1++;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1){
                count2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        int majority = n/3;
        count1=0;
        count2=0;
        for(auto ele : nums){
            if(ele==ele1) count1++;
            if(ele==ele2) count2++;
        }

        if(count1>majority) ans.push_back(ele1);
        if(count2>majority) ans.push_back(ele2);

        sort(ans.begin(),ans.end());
        return ans;
    }
};

// TC : O(N) + O(N)
// SC : O(1)