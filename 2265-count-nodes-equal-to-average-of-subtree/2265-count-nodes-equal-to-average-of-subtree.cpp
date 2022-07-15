
class Solution {
public:
    int ans =0;
    void avg(TreeNode* root , int &n, int &sum)
    {
        if(!root) return;
        sum+=root->val, n+=1;
        avg(root->left, n, sum);
        avg(root->right, n, sum);
    }
    void solve(TreeNode* root)
    {
        if(root == NULL) return;
        int n = 0, sum = 0;
        avg(root, n, sum);
        if(root->val == sum/n) ans++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) 
    {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};