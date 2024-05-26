class Solution {
    bool f(TreeNode* root,long long min,long long max)
    {
        if(root==NULL) return true;

        if(root->val>min && root->val<max)
        {
            bool left=f(root->left,min,root->val);
            bool right=f(root->right,root->val,max);
            return left && right;
        }
        else
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root,LONG_MIN,LONG_MAX);
    }
};
