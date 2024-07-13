class Solution {
public:
    double myPow(double x, int n) {
        // OPTIMAL

        long long non_neg = n;
        if(n<0){
            non_neg = -1*non_neg;
        }

        double ans=1;
        while(non_neg>0){
            // for odd n
            if(non_neg%2==1){
                ans = ans*x;
                non_neg = non_neg-1;
            }
            // for even n
            else{
                x=x*x;
                non_neg = non_neg/2;
            }
        }

        if(n<0) return 1/ans;

        return ans;
    }
};

// TC : O(logn)
// SC : O(1)