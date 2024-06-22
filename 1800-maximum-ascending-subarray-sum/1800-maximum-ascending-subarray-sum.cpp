class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int len=nums.size();
        int i,j;
        int sum=0;
        int maxSum=INT_MIN;
        for(i=0;i<len;i++)
        {
            sum=0;
            for(j=i;j<len;j++)
            {
                sum+=nums[j];
                maxSum = max(maxSum, sum);
                if(j<len-1 && nums[j]>=nums[j+1])
                    break;
            }
        }
        return maxSum;
    }
};