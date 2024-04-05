class Solution {
    int dfs(int i, int t, int n, vector<int> &nums, vector<vector<int>> &dp) {
        if(!t) return 1;
        if(i == n) return 0; 
        if(dp[i][t] != -1) return dp[i][t];

        int pick = nums[i] <= t ? dfs(0, t - nums[i], n, nums, dp) : 0;
        int notpick = dfs(i + 1, t, n, nums, dp);

        return dp[i][t] = pick + notpick;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return dfs(0, target, n, nums, dp);
    }
};