class Solution {
public:
TreeNode* deleteNode(TreeNode* root, int key) {
if(root==NULL)return NULL;
​
if(key<root->val){
root->left=deleteNode(root->left,key);
}
else if(key>root->val){
root->right=deleteNode(root->right,key);
}
else{
if(!root->left && !root->right){
delete root;
return NULL;
}
else if(!root->left || !root->right){
TreeNode* temp=root->left?root->left:root->right;
delete root;
return temp;
}
else if(root->left && root->right){
TreeNode* temp=root;
temp=temp->left;
while(temp->right)temp=temp->right;
root->val=temp->val;
root->left=deleteNode(root->left,temp->val);
}
}
return root;
}
};