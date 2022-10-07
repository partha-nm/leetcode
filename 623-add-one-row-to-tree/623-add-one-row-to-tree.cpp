class Solution {
public:
    void buildTree(TreeNode*root,int val,int depth,int level){
        if(!root || level>depth)return;
        if(level==depth-1){
				
				root->left = new TreeNode(val, root->left, nullptr);
				root->right = new TreeNode(val, nullptr, root->right);
            return;
        }
        buildTree(root->left,val,depth,level+1);
        buildTree(root->right,val,depth,level+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        buildTree(root,val,depth,1);
        return root;
    }
};