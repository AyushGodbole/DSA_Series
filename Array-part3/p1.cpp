class Solution {
private:
    bool binarySearch(vector<int> row, int target){
        int left=0;
        int right=row.size()-1;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(row[mid]<target){
                left = mid+1;
            }
            else if(row[mid]>target){
                right = mid-1;
            }
            else{
                return true;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // BETTER

        // going to every row , and check if target lies in (arr[row][0],arr[row][n-1])
        // if so, then do a bs on it
        int n=matrix.size();
        int m=matrix[0].size();

        for(int row=0; row<n; row++){
            if(target>=matrix[row][0] && target<=matrix[row][m-1]){
                bool res = binarySearch(matrix[row],target);
                return res;
            }
        }

        return false;
    }
};

// TC : O(N) + O(logm)
// SC : O(1)