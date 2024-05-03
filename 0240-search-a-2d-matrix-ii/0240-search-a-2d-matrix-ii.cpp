class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();

	int i=0,j=n-1;     // start from the top right corner. 

	while(i<m&&j>=0){
		if(matrix[i][j]==target) return true;    // target found 

		if(matrix[i][j]<target)    
			i++;   // because all the element < jth index in ith row is less than current and
			          // elements > jth index in ith row are already searched. 
		else
			j--;   // all the element < jth index of <ith row are less and 
			        // jth element of i+1th row is greater than curr.
	}
	return false;
    }
};