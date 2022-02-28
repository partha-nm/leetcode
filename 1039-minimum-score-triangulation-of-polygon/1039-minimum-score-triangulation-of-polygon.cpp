class Solution {
public:
    int solve(vector<int>&v, int i, int j, vector<vector<int>>&dp)
    {
        if(dp[i][j] !=  -1) return dp[i][j];
        if(i>=j) return dp[i][j] = 0;
        
        int mn = INT_MAX;
        
        for(int k=i; k<j; k++)
        {
            int temp = solve(v, i, k, dp) + solve(v, k+1, j, dp) + v[i-1]*v[k]*v[j];
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }
    int minScoreTriangulation(vector<int>& v) 
    {
       int n = v.size();
       vector<vector<int>>dp(n, vector<int>(n, -1));
       int i=1, j=v.size()-1;
        return solve(v, i,j, dp);
    }
};