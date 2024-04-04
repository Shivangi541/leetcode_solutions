class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int> &nums, int i, int size){
    
    //base case: if the counter reaches the end of the vector
    if(i==size){
        //add the temporary vector elements to the big one
        ans.push_back(nums);
        return;
    }
    
    //loop over the whole vector elements
    for(int j=i;j<=size;j++){
        
        //do swapping
        swap(nums[i], nums[j]);
        //recursivelly, backtrack
        backtrack(ans, nums, i+1, size);
        //undo
        swap(nums[i], nums[j]);
    }
    
}

vector<vector<int>> permute(vector<int>& nums) {
    
    //initialize a result vector
    vector<vector<int>> ans;
    
    //call the helper function
    backtrack(ans, nums, 0, nums.size()-1);
    
    //return the final result elements
    return ans;
}

};