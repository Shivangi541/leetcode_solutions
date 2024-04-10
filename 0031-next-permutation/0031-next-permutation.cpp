class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx=i;
                break;
            }
        }

        if(idx!=-1)
        {
          int mini=INT_MAX;
          int jdx=-1;
          for(int i=idx+1; i<n; i++)
          {
              if(nums[i]>nums[idx])
              {
                  if(nums[i]<mini)
                  {
                      mini=nums[i];
                      jdx=i;
                  }
              }
          }
          if(jdx!=-1){
          swap(nums[jdx],nums[idx]);}
        }
        sort(nums.begin()+idx+1,nums.end());
    }
};