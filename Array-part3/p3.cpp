class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // OPTIMAL - moore's voting algo

        int count=0;
        int ele;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(count==0){
                ele = nums[i];
                count++;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }

        int majority = n/2;
        int eleCount=0;
        for(int i=0; i<n; i++){
            if(nums[i]==ele) eleCount++;
        }

        if(eleCount>majority) return ele;
        return -1;
    }
};

// TC : O(N) + O(N)
// SC : O(1)