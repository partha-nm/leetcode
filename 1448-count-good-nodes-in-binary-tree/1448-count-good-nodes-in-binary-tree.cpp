/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =0;
    void solve(TreeNode *root, int val)
    {
        if(!root) return;
        if(root->val >= val) ans++;
        if(root->left)
        {
            int p = max(val, root->left->val);
            solve(root->left, p);
        }
        if(root->right)
        {
            int p = max(val, root->right->val);
            solve(root->right, p);
        }
    }
    int goodNodes(TreeNode* root) {
        int val = root->val;
        solve(root, val);
        return ans;
    }
};