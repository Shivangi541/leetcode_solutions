binary search is performed on the 2d array because it is sorted
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
// brute force
int n= matrix.size();// row size
int m= matrix[0].size();// column size
// linear search
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(matrix[i][j]==target)
return true;
}
}
return false;
}
};