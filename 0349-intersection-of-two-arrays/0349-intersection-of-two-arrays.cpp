class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         set<int>st;
       vector<int>result;
       for(auto ele:nums1){
           for(auto it:nums2){
               if(ele==it){
                   st.insert(ele);
               }
           }
       }
       for(auto itr:st){
           result.push_back(itr);
       }
       return result;

         /*vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());//Erasing all the duplicate elements.
        return ans;*/
    }
};