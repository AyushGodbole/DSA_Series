class Solution {

private:
    void BFS(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};

        while(!q.empty()){
            int rowD = q.front().first;
            int colD = q.front().second;
            q.pop();

            // traverse all neighbours in 4 directions
                for(int k=0; k<4; k++){
                int nrow = rowD+delRow[k];
                int ncol = colD+delCol[k];

                // check if not visited
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]=='1' &&!vis[nrow][ncol]){

                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    BFS(row,col,vis,grid);
                    count++;
                }
            }
        }

        return count;
    }
};

// TC : O(N^2)
// SC : O(NxM) + O(n+m)