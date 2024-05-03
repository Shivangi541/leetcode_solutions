class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m= mat[0].size();
        int index=-1,maxi=-1;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int cntrow=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    cntrow+=mat[i][j];
                }
            }
                if(cntrow>maxi)
                {
                   
                    index=i;
                }
                maxi=max(maxi,cntrow);
              
             // return {index,maxi};
        }
        return {index,maxi};
    }
};