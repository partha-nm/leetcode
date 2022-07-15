class Solution {
public:
    vector<vector<int>>dir = {{1,0},{-1,0},{0, 1}, {0,-1}};
    void solve(int i, int j, vector<vector<int>>&grid, int &res)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if(grid[i][j] == 1) {res++; grid[i][j] = -1;}
        else return;
        solve(i+1, j, grid, res);
        solve(i-1, j, grid, res);
        solve(i, j+1, grid, res);
        solve(i, j-1, grid, res);
        
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
                     solve(i, j, grid , res);
                     ans = max(res , ans);
                 }
             }
         }
        return ans;
    }
};