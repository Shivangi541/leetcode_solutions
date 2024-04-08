class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        std::vector<std::vector<int>> dp(m + 2, std::vector<int>(m + 2, 0));

        for (int s = 2; s <= m + 1; s++) {
            for (int i = 0; i + s <= m + 1; i++) {
                int j = i + s;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) 
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                int left, right;
                left = (i == 0) ? 0 : cuts[i - 1];
                right = (j == m + 1) ? n : cuts[j - 1];
                dp[i][j] += right - left;
            }
        }
        return dp[0][m + 1];
    }
};