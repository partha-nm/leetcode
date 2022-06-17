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
    int solve(TreeNode* root)
    {
        if(root == NULL) return 1;
        int lft = solve(root->left);
        int rgt = solve(root->right);
        if(lft == -1 || rgt == -1)
        {
            ans++;
            return 0;
        }
        if(lft == 0 || rgt  == 0) return 1;
        return -1;
        
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1) ans++;
        return ans;
    }
};