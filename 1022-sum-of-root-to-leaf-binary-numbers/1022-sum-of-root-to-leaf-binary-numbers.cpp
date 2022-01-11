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
    void check(TreeNode* root,vector<int>val, int &ans)
    {
        val.push_back(root->val);
        if(!root->left && !root->right)
        {
            int p=val.size()-1;
            int sum =0;
            for(int i=0; i<val.size(); i++) {sum+=val[i]*pow(2,p); p--;}
            ans += sum;
            val.pop_back();
            return;
        }
        if(root->left)check(root->left, val,ans);
        if(root->right)check(root->right, val, ans);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        if(root == NULL) return 0;
        int ans =0;
        vector<int>val;
        check(root,val,ans);
        return ans;
    }
};