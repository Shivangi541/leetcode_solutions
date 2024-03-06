class Solution {
public:
    int profit(int index,int buy,vector<int>& prices,int capacity,vector<vector<vector<int>>>& dp)
    {
        // base case
        if(index==prices.size())
        {
            return 0;
        }
        if(capacity==0)
        {
            return 0;
        }
        if(dp[index][buy][capacity]!=-1)
            return dp[index][buy][capacity];
        
        if(buy==1)
        {
            return dp[index][buy][capacity]=max(-prices[index]+profit(index+1,0,prices,capacity,dp), 0+ profit(index+1,1,prices,capacity,dp));
        }
        else
        {
            return dp[index][buy][capacity]= max(prices[index]+profit(index+1,1,prices,capacity-1,dp),0+profit(index+1,0,prices,capacity,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
       int n= prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return profit(0,1,prices,2,dp);
    }
};