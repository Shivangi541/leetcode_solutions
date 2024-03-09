class Solution {
public:
    int lcs(int ind1,string& text1, int ind2, string& text2,vector<vector<int>>& dp)
    {
        // base case
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
        {
            return dp[ind1][ind2]= 1+ lcs(ind1-1,text1,ind2-1,text2,dp);
        }
        else
        {
           return dp[ind1][ind2]= 0+ max(lcs(ind1,text1,ind2-1,text2,dp),lcs(ind1-1,text1,ind2,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.size();
        int n2= text2.size();
        // memoization
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return lcs(n1-1,text1,n2-1,text2,dp);
    }
};