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
#define ll unsigned long long
class Solution {
public:
   
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL) return 0;
        ll ans =0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty())
        {
            int n = q.size();
            ll mn = q.front().second;
            ll fst,lst;
            for(int i=0; i<n; i++)
            {
                TreeNode *curr = q.front().first;
                ll curr_val = q.front().second-mn;
                q.pop();
                if(i==0) fst = curr_val;
                if(i == n-1) lst = curr_val;
                if(curr->left) q.push({curr->left, 2*curr_val+1});
                if(curr->right) q.push({curr->right, 2*curr_val+2});
            }
            ans = max(ans,lst-fst+1);
        }
        return ans;
    }
};