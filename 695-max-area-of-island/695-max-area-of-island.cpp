class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0, 1}, {0,-1}};
    void solve(int i, int j, vector<vector<int>>&grid, int &res)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = -1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            res++;
            auto curr = q.front();
            q.pop();
            int a = curr.first, b = curr.second;
            for(auto &p:dir)
            {
                int x = p[0] + a;
                int y = p[1] + b;
                if(x < n && x>= 0 && y <m && y >=0)
                {
                    if(grid[x][y] == 1){q.push({x,y}); grid[x][y] = -1;}
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
         int ans =0;
         int n = grid.size(), m = grid[0].size();
         for(int i=0; i<n; i++)
         {
             for(int j=0; j<m; j++)
             {
                 if(grid[i][j] == 1)
                 {
                     int res = 0;
                     // cout<<i<<" "<<j<<endl;
                     solve(i, j, grid , res);
                     ans = max(res , ans);
                 }
             }
         }
        return ans;
    }
};