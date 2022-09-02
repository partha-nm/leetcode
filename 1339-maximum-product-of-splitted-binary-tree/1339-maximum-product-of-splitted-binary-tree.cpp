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
    int mod = 1e9 + 7;
    int findSum(TreeNode* root)
    {
        if(!root) return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    int solve(TreeNode *root, long long &total_sum , long long &product)
    {
        if(!root) return 0;
        long long lh = solve(root->left, total_sum , product);
        product = max(product , (total_sum - lh)* lh);
        long long rh = solve(root->right, total_sum, product);
        product = max(product, (total_sum - rh)* rh);;
        return lh + rh + root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        long long total_sum = findSum(root);
        long long int product = 1;
        solve(root, total_sum ,product);
        return product%mod;
    }
};