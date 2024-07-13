class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // BRUTE FORCE

        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target) return true;
            }
        }

        return false;
    }
};

// TC : O(n^n)
// SC : O(1)