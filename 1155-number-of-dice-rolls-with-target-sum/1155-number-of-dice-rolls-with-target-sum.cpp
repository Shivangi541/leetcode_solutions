long long m = 1e9 + 7;

class Solution {
public:
    long long solve(int n, int i, int t, int k, long long sum, vector<vector<long long>>& vs) {
        // Base case: out of dice
        if (i >= n) {
            return (sum == t) ? 1 : 0;
        }

        // Memoization: If the current state is already computed, return the result
        if (vs[i][sum] != -1) {
            return vs[i][sum];
        }

        long long ans = 0;
        // Explore all possibilities for the current dice
        for (int j = 1; j <= k; j++) {
            if (sum + j <= t) {
                // Recursively call for the next dice and update the result
                ans = (ans + solve(n, i + 1, t, k, sum + j, vs)) % m;
            }
        }

        // Memoize the result and return
        vs[i][sum] = ans;
        return ans;
    }

    int numRollsToTarget(int n, int k, int t) {
        // Check if the target is achievable based on the number of dice and faces
        if (t > k * n || t < n) return 0;

        // Initialize memoization matrix
        vector<vector<long long>> vs(n, vector<long long>(t + 1, -1));
        // Call the solve function with initial parameters
        long long ans = solve(n, 0, t, k, 0, vs);

        return ans;
    }
};
