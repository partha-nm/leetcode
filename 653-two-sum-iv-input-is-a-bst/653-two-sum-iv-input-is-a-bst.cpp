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
    bool ans = false;
    void check(TreeNode *root ,set<int>&m, int k)
    {
       if(root == NULL) return;
       cout<<k-root->val<<" ";
       if(m.find(k-root->val) != m.end()) ans = true;
        m.insert(root->val);
    
        check(root->left, m , k);
        check(root->right, m , k);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        if(root == NULL) return false;
        set<int>m;
        check(root, m , k);
        if(ans) return true;
        return false;
    }
};