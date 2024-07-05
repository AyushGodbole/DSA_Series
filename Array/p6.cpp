class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // BRUTE FORCE , checking each one

        int profit=0;
        int n = prices.size();

        for(int i=0; i<n; i++){
            int num = prices[i];
            int maxNum = num;
            for(int j=i+1; j<n; j++){
                maxNum = max(maxNum,prices[j]);
            }

            int diff = (maxNum-num);
            profit = max(profit,diff);
        }

        return profit;
    }
};

// TC : O(n*n)
// SC : O(1)