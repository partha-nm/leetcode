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
    bool isPalindrome(vector<int>v)
    {
        int odd =0;
        for(auto &x:v) if(x&1) odd++;
        if(odd > 1) return false;
        return true;
    }
    void solve(TreeNode* root, vector<int>v)
    {
        if(!root) return;
        int p = root->val;
        v[p]++;
        if(!root->left && !root->right)
        {
            if(isPalindrome(v)) ans++;
            return;
        }
        solve(root->left, v);
        solve(root->right, v);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        vector<int>v(10, 0);
        solve(root, v);
        return ans;
    }
};