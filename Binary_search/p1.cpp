class Solution {
private:
    int solve(int low, int high, vector<int> &nums, int target){
        if(low>high) return -1;

        int mid = low + (high-low)/2;

        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return solve(mid+1,high,nums,target);
        else return solve(low,mid-1,nums,target);
    }
public:
    int search(vector<int>& nums, int target) {
        // recursive

        int n=nums.size();
        return solve(0,n-1,nums,target);
    }
};