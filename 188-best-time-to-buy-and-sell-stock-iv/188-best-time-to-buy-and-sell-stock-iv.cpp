class Solution {
public:
    int solve(vector<int>p, int n, int i,int buy, int k, vector<vector<vector<int>>>&dp)
    {
        if(k == 0) return 0;
        if(i == n) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        if(buy) return dp[i][buy][k] = max(-p[i]+solve(p,n,i+1,0,k,dp), solve(p,n,i+1,1,k,dp));
        else return dp[i][buy][k] = max(p[i]+solve(p,n,i+1,1,k-1,dp),solve(p,n,i+1,0,k,dp));
    }
    int maxProfit(int k, vector<int>& prices) 
    {
       int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,n, 0 , 1, k, dp);
    }
};