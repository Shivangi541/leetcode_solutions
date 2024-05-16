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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                mp[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                mp[temp->right]=temp;
            }
        }
        q.push(target);
        int count=0;
        vector<int>ans;
        unordered_map<TreeNode*,int>mp1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                mp1[temp]++;
                if(temp->left && !mp1[temp->left])
                q.push(temp->left);
                if(temp->right && !mp1[temp->right])
                q.push(temp->right);
                if(!mp1[mp[temp]] && mp[temp])
                q.push(mp[temp]);
                if(count==k)
                ans.push_back(temp->val);
            }
            count++;
            if(count==k+1)
            break;
        }
        return ans;
    }
};