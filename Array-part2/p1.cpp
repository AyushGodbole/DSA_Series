class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // OPTIMAL
        int n = matrix.size();

        // 1. take transpose of matrix
        for(int i=0; i<=n-1; i++){
            for(int j=i+1; j<=n-1; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // 2. reverse every row
        for(int i=0; i<=n-1; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// TC : O(n^2)
// SC : O(1)