class Solution {
public:
    TreeNode* buildprocess(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int postart,int poend,map<int,int>&m){
        if(instart>inend || postart>poend){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[poend]);
        int index=m[postorder[poend]];
        int gap=index-instart;
        root->left=buildprocess(inorder,instart,index-1,postorder,postart,postart+gap-1,m);
        root->right=buildprocess(inorder,index+1,inend,postorder,postart+gap,poend-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=buildprocess(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
        return root;
        
    }
};