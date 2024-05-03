class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ind,mx=-1;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            sort(mat[i].begin(),mat[i].end());
            int s=0,e=mat[i].size()-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(mat[i][mid]==0){
                    s=mid+1;
                } else {
                    e=mid-1;
                }
            }
            if(mx<n-s){
                mx=n-s;
                ind=i;
            }
        }
        return {ind,mx};
    }
};;