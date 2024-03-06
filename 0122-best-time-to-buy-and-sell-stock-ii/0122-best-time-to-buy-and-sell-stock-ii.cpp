class Solution {
public:
    int solveMem(int index,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(index == prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;

        if(buy)
        {
            int Buy = -prices[index] + solveMem(index+1,0,prices,dp);
            int skip = 0 + solveMem(index+1,1,prices,dp);
            profit = max(Buy,skip);
        }
        else
        {
            int sell = prices[index] + solveMem(index+1,1,prices,dp);
            int skip = 0 + solveMem(index+1,0,prices,dp);
            profit = max(sell,skip);
        }

        dp[index][buy] = profit;
        return dp[index][buy];
    }

    int maxProfit(vector<int>& prices) {
       int n = prices.size();
         vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solveMem(0,1,prices,dp); 
    }
};