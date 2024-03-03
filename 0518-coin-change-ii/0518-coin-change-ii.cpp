class Solution {
public:
    int solve(int i,vector<int>& coins,int amt,vector<vector<int>>& dp)
   {   
        if(amt==0)
            return 1;
       if(i==0)  //base case
       {
           if(amt%coins[0]==0)
           return 1;
           return 0;
       }
        if(dp[i][amt]!=-1)
            return dp[i][amt];
       int pick=0,notpick=0;
       if(coins[i]<=amt) //We wil only pick if the value of coins[i] is less than the amt.
       {
         pick=solve(i,coins,amt-coins[i],dp);
       }
       notpick=solve(i-1,coins,amt,dp);
       return dp[i][amt]= pick+notpick;
   }
    int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1,-1));
    return solve(n-1,coins,amount,dp);
    }
};