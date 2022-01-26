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
    void insert(TreeNode *root, vector<int>&v)
    {
        if(root == NULL) return;
        insert(root->left, v);
        v.push_back(root->val);
        insert(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
      vector<int>ans, v1,v2;
        insert(root1, v1);
        insert(root2, v2);
        int n = v1.size(), m = v2.size();
        ans = v1;
        for(int i=0; i<m; i++) ans.push_back(v2[i]);
        sort(ans.begin(), ans.end());
        return ans;
    }
};