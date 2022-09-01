class Solution {
public:
    
    int numDistinct(string s, string t) 
    {
         int i =0, j =0;
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>>dp(n+1, vector<unsigned long long>(m+1, 0));
        // dp[n][m] = 1;
        for(int i=n; i>=0; i--)
        {
            for(int j=m; j>=0; j--)
            {
                if(i == n && j == m) dp[i][j] = 1;
                else if(i == n) dp[i][j] = 0;
                else
                {
                    if(s[i] == t[j]) dp[i][j] = dp[i+1][j] + dp[i+1][j+1];
                    else dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};