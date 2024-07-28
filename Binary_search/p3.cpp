class Solution {
  private:
    int findFloor(int low, int high, vector<int> &arr, int x) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] <= x) {
                ans = mid;
                // We may get largest in right <= x
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if(ans==-1) return ans;
        return arr[ans];
    }
    
    int findCiel(int low, int high, vector<int> &arr, int x) {
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] >= x) {
                ans = mid;
                // We may get smallest in left >= x
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if(ans==-1) return ans;
        return arr[ans];
    }
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int low = 0;
        int high = arr.size()-1;
        sort(arr.begin(),arr.end());
        
        int lower = findFloor(low,high,arr,x);
        int upper = findCiel(low,high,arr,x);
        
        return {lower,upper};
    }
};