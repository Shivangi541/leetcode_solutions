/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if we reach null then return null 
        if(!root)
            return NULL;
        //get the current node value
        int curr=root->val;
        //check if the current node's value is less than p and q's value then go right 
        if(curr<p->val&&curr<q->val)
            return lowestCommonAncestor(root->right,p,q);
        //if the current node's value is greater than p's and q's value then go left
        if(curr>p->val&&curr>q->val)
            return lowestCommonAncestor(root->left,p,q);
        //if not the above case then we got the lca (either of the p or q is the current node or only one of the node is on left or right side not both of them ) hence the current node will be lca
        return root;
    }
};