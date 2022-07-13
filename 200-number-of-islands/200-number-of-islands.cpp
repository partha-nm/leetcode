class Solution {
public:
    
    vector<vector<int>>dir = {{1,0},{-1,0}, {0,1},{0,-1}};
    
    void solve(vector<vector<char>>&grid, int i , int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
           grid[i][j] = '2';
        while(!q.empty())
        {
            pair<int,int>curr = q.front();
            q.pop();
            int a = curr.first, b = curr.second;
            for(auto c:dir)
            {
                int x = c[0] + a;
                int y = c[1] + b;
                if(x >= 0 && x <n && y >=0 && y<m)
                {
                    if(grid[x][y] == '1') 
                    {
                        grid[x][y] = '2';
                        q.push({x,y});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m;  j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    solve(grid, i, j);
                }
            }
        }
        return ans;
    }
};