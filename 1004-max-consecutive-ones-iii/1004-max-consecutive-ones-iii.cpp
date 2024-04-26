class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int high=0;
        int low=0;
        int count=0;
        int maxi=0;
        while(high!=nums.size() && low<=high )
        {
            while(high!=nums.size() && count<=k)
            {
                
                if(nums[high]==0)   count++;
                if(count<=k)
                {
                int window=high-low+1;
                maxi=max(maxi,window);
                }
                high++;

            }
            while(count>k)
            {
                if(nums[low]==0)    count--;
                low++;
            }
            
        }
        return maxi;
        
    }
};