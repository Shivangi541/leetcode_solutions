class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      /*  sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            return nums[i];
        }   
        return -1;*/

        set<int>s;
        for(auto i:nums){
            if(s.find(i)==s.end()){
                s.insert(i);
            }
            else{
                return i;
            }
        }
        return -1;
    }

};