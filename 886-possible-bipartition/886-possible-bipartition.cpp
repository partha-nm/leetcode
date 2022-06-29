class Solution {
public:
    set<int>st1,st2;
    vector<bool>visited;
    bool solve(vector<int>adj[], int node)
    {
        queue<int>q;
        q.push(node);
        st1.insert(node);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(!visited[curr])
            {
                visited[curr] = true;
                 bool flag1 =false, flag2 = false;
            if(st1.find(curr) != st1.end()) flag1 = true;
            else if(st2.find(curr) != st2.end()) flag2 = true;
            for(int x:adj[curr])
            {
                if(flag1)
                {
                    if(st1.find(x) != st1.end()) return false;
                    st2.insert(x);
                }
                else if(flag2)
                {
                    if(st2.find(x) != st2.end()) return false;
                    st1.insert(x);
                }
                q.push(x);
            }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        if(dislikes.size() == 0) return true;
        vector<int>adj[n+1];
        for(int i=0; i<dislikes.size(); i++)
        {
            int p = dislikes[i][0], q = dislikes[i][1];
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
        visited.resize(n+1, false);
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                if(solve(adj, i) == false) return false; 
            }
        }
        return true;
    }
};