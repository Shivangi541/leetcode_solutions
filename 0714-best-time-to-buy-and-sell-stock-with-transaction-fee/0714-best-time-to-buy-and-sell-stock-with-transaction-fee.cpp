class Solution {
public:
    int profit(int index,int buy, vector<int>& prices,int fee,vector<vector<int>>& dp)
    {
        // base case
        if(index== prices.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int p=0;
        if(buy==1)
        {
            int b= -prices[index]+profit(index+1,0,prices,fee,dp);
            int nb= 0+ profit(index+1,1,prices,fee,dp);
            p=max(b,nb);
        }
        else
        {
            int s= prices[index]-fee + profit(index+1,1,prices,fee,dp);
            int ns= 0+ profit(index+1,0,prices,fee,dp);
            p= max(s,ns);
        }
        return dp[index][buy]=p;
        
        
        // transaction fee is deducted only after completion of a sell
    }
    int maxProfit(vector<int>& prices, int fee) {
        // recursion
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return profit(0,1,prices,fee,dp);
        // 1= buy
        //0= sell
    }
};