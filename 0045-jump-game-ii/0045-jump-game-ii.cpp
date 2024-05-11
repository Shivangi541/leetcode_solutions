class Solution {
public:
   int jump(vector<int>& nums) {
    if(nums.size()==1) return 0;
    vector<int> dp(nums.size(), -1);
    return f(0,nums,dp)+1;
}

int f(int i, vector<int>& nums, vector<int> &dp){
    int j=i+nums[i];
    if(j>=nums.size()-1) return 0;

    if(dp[i]!=-1) return dp[i];
    
    int mini=1e7;
    for(int k=i+1;k<=j;k++){
        int steps=1+f(k,nums,dp);
        mini=min(mini, steps);
    }

    return dp[i]=mini;
}

};