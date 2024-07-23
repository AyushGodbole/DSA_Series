/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    
    // CUSTOM COMPARATOR
    static bool comparator(Item it1, Item it2){
        double r1 = (double)it1.value / (double)it1.weight;
        double r2 = (double)it2.value / (double)it2.weight;
        if(r1>r2) return true;
        return false;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        // sort array according to value to weight ratio
        sort(arr,arr+n,comparator);
        
        double ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i].weight<=w){
                ans+=arr[i].value;
                w = w-arr[i].weight;
            }
            else{
                // take fraction
                ans += ( (double(arr[i].value)/double(arr[i].weight))*w );
                break;
            }
        }
        
        return ans;
    }
};

// TC : O(NlogN) + O(N)
// SC : O(1)