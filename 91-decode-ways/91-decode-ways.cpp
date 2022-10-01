class Solution {
public:
    vector<int>dp;
    
    int solve(string s, int i, int n)
    {
        if(dp[i] != -1) return dp[i];
        if(i< n && s[i] == '0') return 0;
        if(i>=n-1)
        {
            if(s[i] == '0') return 0;
            else return 1;
        }
        int p = 10*(s[i] - '0') + (s[i+1] - '0');
        int ans = solve(s,i+1, n);
        if(p < 27) ans+=solve(s,i+2, n);
        return dp[i] = ans;
    }
    int numDecodings(string s) 
    {
       int n = s.size();
       if(s[0] == '0') return 0;
        for(int i=1;i<n; i++)
        {
            if(s[i] == '0')
            {
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
            }
        }
        dp.resize(102, -1);
       return solve(s,0,n);
    }
};