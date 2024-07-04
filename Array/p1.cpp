//  SET MATRIX ZERO


class Solution {
public:

    void makeRow(int row , vector<vector<int>> &mat){
        int m = mat[0].size();
        for(int j=0; j<m; j++){
            if(mat[row][j]!=0){
                mat[row][j] = -1;
            }
        }
    }

    void makeCol(int col , vector<vector<int>> &mat){
        int n = mat.size();
        for(int j=0; j<n; j++){
            if(mat[j][col]!=0){
                mat[j][col] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // brute force
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    makeRow(i,matrix);
                    makeCol(j,matrix);
                }
            }
        }

        // replace -1 to 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==-1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// TC : O(n^3)
// SC : O(1)
