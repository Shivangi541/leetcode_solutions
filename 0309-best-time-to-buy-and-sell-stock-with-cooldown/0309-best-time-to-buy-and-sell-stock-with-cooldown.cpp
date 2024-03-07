class Solution {
public:
    int f(int i,int b,vector<int>& p,int n,vector<vector<int>>& dp){
		if(i>=n) return 0;
        if(dp[i][b]!=-1)
            return dp[i][b];
		int profit;
		if(b){
			int buy=-p[i]+f(i+1,0,p,n,dp);
			int notbuy=f(i+1,1,p,n,dp);
			profit=max(buy,notbuy);
		}
		else{
			int sell=p[i]+f(i+2,1,p,n,dp);
			int notsell=f(i+1,0,p,n,dp);
			profit=max(sell,notsell);
		}
		return dp[i][b]=profit;
	}

	int maxProfit(vector<int>& p) {
		int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
		return f(0,1,p,n,dp);
	}
};