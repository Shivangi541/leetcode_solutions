class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force
        int i,j,k;
        int len=nums.size();
        int sum=0;
        int maxi=nums[0];
        
        // edge case
        if(len==1)
            return nums[0];
        for(i=0;i<len;i++)
        {    
           sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
                sum=0;
             
        }
        return maxi;
    }
};