class Solution {
public:
    bool wordBreak(string s, vector<string>& w) 
    {
        vector<bool>dp(s.size(),false);
        dp[0]=true;
        
        for(int i = 0; i <= s.size(); i++)
        {
            for(auto str: w)
            {
                if(dp[i])
                {
                    if(s.substr(i,str.size()).compare(str)==0)
                    {
                        dp[i+str.size()]=true;
                    }
                }
            }
        }return dp[s.size()];
    }
};