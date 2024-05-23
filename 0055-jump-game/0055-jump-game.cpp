class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for (int i = 0; i < n; i++) {
            // (i > reach) will cover [1,1,0,1,2] or [0,0,0....]
            if(i > reach || reach >= n-1)
                break;
            //this reach will store upto which index we can jump from that ith index
            reach = max(reach, i + nums[i]);
        }
        if (reach >= n-1)
            return true;
        //this "return false" means definitely (i > reach) at any point
        return false;
    }
};