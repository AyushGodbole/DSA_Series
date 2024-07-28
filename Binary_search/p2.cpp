class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &arr, long long n, long long x) {
    int low = 0;
    int high = n - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid]<=x){
            ans = mid;
            // we may find largest ahead < x
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    
    return ans;
}
};