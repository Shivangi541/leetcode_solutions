class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
// brute force: linear search
int row=matrix.size();
int col=matrix[0].size();
// int i,j;
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(matrix[i][j]==target)
return true;
}
}
return false;
}
};