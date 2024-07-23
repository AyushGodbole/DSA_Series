class Solution 
{
    public:
    
    bool static comparator(Job j1, Job j2){
        if(j1.profit>j2.profit) return true;
        return false;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort job array on basis of profit 
        sort(arr,arr+n,comparator);
        
        // find maximum deadline
        int maxDeadline = -1;
        for(int i=0; i<n; i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        
        // create array of max deadline
        vector<int> nums((maxDeadline+1),-1);
        
        // iterate and count jobs and profit
        int count=0;
        int totalProfit=0;
        for(int i=0; i<n; i++){
            // check if job can be done or not
            for(int j=arr[i].dead; j>0; j--){
                if(nums[j]==-1){
                    totalProfit+=arr[i].profit;
                    nums[j] = arr[i].id;
                    count++;
                    break;
                }
            }
        }
        
        vector<int> ans = {count,totalProfit};
        return ans;
    } 
    
};