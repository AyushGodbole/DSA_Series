class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// OPTIMAL - Check Time Clock
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0;
    	int j=0;
    	
    	int count=0;
    	int maxi = -1;
    	while(i<n){
    	    if(arr[i]<=dep[j]){
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    
    	    maxi = max(maxi,count);
    	}
    	
    	return maxi;
    }
};

// TC : O(NlogN) + O(NlogN) + O(2N)
// SC : O(1)