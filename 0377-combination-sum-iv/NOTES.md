int solve(vector<int> nums, int target, int index){
if(target == 0)
return 1;
if(target < 0)
return 0;
​
int ans = 0;
for(int i = 0; i < nums.size(); i++){
ans += solve(nums, target - nums[i], i);
}
return ans;
}
return solve(nums, target, 0);