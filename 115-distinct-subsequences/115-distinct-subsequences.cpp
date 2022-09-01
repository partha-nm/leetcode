class Solution {
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp)
    {
        if(s.size() == i && t.size() == j) return 1; 
        if(s.size() == i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
        {
            return dp[i][j] = solve(s, t, i+1, j, dp) + solve(s, t, i+1, j+1, dp);
        }
        else
        {
            return dp[i][j] = solve(s, t , i+1, j, dp);
        }
    }
    int numDistinct(string s, string t) 
    {
        int i =0, j =0;
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s, t, i, j, dp);
    }
};