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
    vector<vector<int>>ans;
    void check(TreeNode *root, int ts,vector<int>res)
    {
        if(!root) return;
        res.push_back(root->val);
        if(root->val == ts && !root->left && !root->right) ans.push_back(res);
        check(root->left, ts-root->val, res);
        check(root->right, ts-root->val, res);
        res.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        int sum = 0;
        vector<int>res;
        check(root, targetSum, res);
        return ans;
    }
};