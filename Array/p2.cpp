class Solution {
public:

    int ncr(int n , int r){
        long long res = 1;
        for(int i=0; i<r; i++){
            res = res*(n-i);
            res = res/(i+1);
        }

        return res;
    }

    vector<vector<int>> generate(int numRows) {
        // BRUTE FORCE

        vector<vector<int>> res;

        for(int row=1; row<=numRows; row++){
            vector<int> temp;
            for(int col=1; col<=row; col++){
                int num = ncr(row-1,col-1);
                temp.push_back(num);
            }
            res.push_back(temp);
        }

        return res;
    }
};

// TC : O(n*n*n)
// SC : O(1)