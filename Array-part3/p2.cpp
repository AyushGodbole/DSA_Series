class Solution {
private:
    double solve(double x, int n){
        double long ans=1;
        for(int i=1; i<=n; i++){
            ans = ans*x;
        }

        return ans;
    }
public:
    double myPow(double x, int n) {
        // BRUTE FORCE

        if(n==0) return 1;

        if(n<0){
            n = abs(n);
            double res = solve(x,n);
            res = 1/res;
            return res;
        }

        return solve(x,n);
    }
};

// TC : O(N)
// SC : O(1)