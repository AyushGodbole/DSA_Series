class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // OPTIMAL - using hypothetical 1D Array and applying  Binary Search on it

        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=(n*m)-1;

        while(low<=high){
            int mid = low+(high-low)/2;

            // calcuate mid in terms of 2D matrix
            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low = mid+1;
            else high = mid-1;
        }

        return false;
    }
};

// TC : O(log(m*n))
// SC : O(1)