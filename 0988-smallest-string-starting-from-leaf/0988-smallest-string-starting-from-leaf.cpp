class Solution {
public:
    void helper(TreeNode* root, string s, string& ans) {
        if (!root)
            return;
        s += ('a' + root->val);
        helper(root->left, s, ans);
        if (!root->left && !root->right) {
            string temp = s;
            reverse(temp.begin(), temp.end());
            if (ans.empty() || ans > temp)
                ans = temp;
        }
        helper(root->right, s, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans, s;
        helper(root, s, ans);
        return ans;
    }
};