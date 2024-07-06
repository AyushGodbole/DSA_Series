class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // BRUTE FORCE
        vector<vector<int>> ans;

        // 1. sort the array
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        // 2. check for each
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }

            for(int j=i+1; j<n; j++){
                if(intervals[j][0]<=end){
                    end = max(end,intervals[j][1]);
                }
                else{
                    break;
                }
            }

            ans.push_back({start,end});
        }

        return ans;
    }
};

// TC : O(nlogn) + O(2n)
// SC : O(1)