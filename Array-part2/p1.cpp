// ROTATE MATRIX BY 90

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // BRUTE FORCE
        
        int n = matrix.size();
        vector<vector<int>> res(n,vector<int>(n));
        int k=0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=n-1; j++){
                res[j][i] = matrix[k][j];
            }
            k++;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = res[i][j];
            }
        }
    }
};

// TC : O(n^2) + O(n^2)
// SC : O(NxN)