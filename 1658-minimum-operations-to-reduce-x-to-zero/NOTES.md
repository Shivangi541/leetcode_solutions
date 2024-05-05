class Solution {
int minCount;
public:
void solve(vector<int>& nums, int remain, int count, int i, int j) {
if (remain == 0) {
minCount = min(minCount, count);
return;
}
else if (remain < 0 || i > j || count >= minCount)
return;
else {
solve(nums, remain - nums[i], count + 1, i + 1, j);
solve(nums, remain - nums[j], count + 1, i, j - 1);
}
}
int minOperations(vector<int>& nums, int x) {
int n = nums.size();
minCount = INT_MAX;
​
solve(nums, x, 0, 0, n-1);
if (minCount == INT_MAX)
return -1;
return minCount;
}
};