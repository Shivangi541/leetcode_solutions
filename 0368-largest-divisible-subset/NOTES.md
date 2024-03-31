class Solution {
public:
vector<int> temp;
void solve(int i, vector<int> &nums, vector<int> &ans){
if(i >= nums.size()){
if(ans.size() > temp.size()){
temp = ans;
}
return;
}
​
​
if(ans.size() == 0 || nums[i] % ans.back()  == 0){
ans.push_back(nums[i]);
solve(i+1, nums, ans);
ans.pop_back();
}
​
solve(i+1, nums, ans);
​
​
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
vector<int> ans;
sort(nums.begin(), nums.end());
solve(0, nums, ans);
return temp;
}
};