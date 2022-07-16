class Solution {
public:
    int dp[52][52][52];
    int mod = 1e9 + 7;
    int solve(int m, int n, int maxMove, int x, int y)
    {
        if(x <0 || x >= m || y < 0 || y >= n)
        {
            return 1;
        }
        if(maxMove == 0) return 0;
        if(dp[x][y][maxMove] != -1) return dp[x][y][maxMove];
        int a = solve(m, n, maxMove-1, x-1, y);
        a = (a + solve(m, n, maxMove-1, x+1, y))%mod;
        a = (a + solve(m, n, maxMove-1, x, y-1))%mod;
        a = (a + solve(m, n, maxMove-1, x, y+1))%mod;
        return dp[x][y][maxMove] = a;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(dp , -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn)%mod;
    }
};