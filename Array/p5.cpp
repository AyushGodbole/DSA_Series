class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) zero++;
            else if (nums[i]==1) one++;
            else two++;
        }

        int i = 0;
        int n = nums.size();

        while(i<n){
            if(zero-->0){
                nums[i] = 0;
            }
            else if(one-->0){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
                two--;
            }
            i++;
        }
    }
};

// TC : O(n) + O(n)
// SC : O(1)