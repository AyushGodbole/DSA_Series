class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // OPTIMAL
        vector<vector<int>> ans;

        // 1. sort the array
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        for(int i=0; i<n; i++){

            // check if new interval
            if(ans.empty() || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
            
        }

        return ans;
    }
};

// TC : O(nlogn) + O(n)
// SC : O(1)