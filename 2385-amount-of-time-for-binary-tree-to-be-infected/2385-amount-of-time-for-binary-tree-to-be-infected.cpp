
class Solution {
public:
    map<int, vector<int>>graph;
    void solve(TreeNode *root)
    {
        if(!root) return;
        if(root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        solve(root->left);
        solve(root->right);
    }
    int amountOfTime(TreeNode* root, int start) 
    {
         solve(root);
         map<int,bool>visited;
         queue<int>q;
         q.push(start);
         visited[start] = true;
        int ans =0;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i =0; i<sz; i++)
            {
                int curr = q.front();
                q.pop();
                for(auto x:graph[curr])
                {
                    if(!visited[x])
                    {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }
        return ans-1;
    }
};