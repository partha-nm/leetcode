class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(3, 0));
        int rem = nums[0]%3;
        dp[0][rem] = nums[0];
        for(int i=1; i<n; i++)
        {
            if(nums[i] % 3 == 0)
            {
                dp[i][0] = nums[i] + dp[i-1][0];
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
                if(dp[i-1][1]) dp[i][1] += nums[i];
                if(dp[i-1][2]) dp[i][2] += nums[i];
            }
            else if(nums[i]  % 3 == 1)
            {
                 dp[i][0] = dp[i-1][0];
                 dp[i][1] = max(dp[i-1][1], nums[i] + dp[i-1][0]);
                 dp[i][2] = dp[i-1][2];
                if(dp[i -1][2])
                {
                    dp[i][0] =max(dp[i][0], nums[i] + dp[i-1][2]);
                    // dp[i][1] += dp[i][2];
                }
                if(dp[i-1][1]) dp[i][2] = max(dp[i-1][2] ,dp[i-1][1] + nums[i]); 
            }
            else
            {
                 dp[i][0] = dp[i-1][0];
                 dp[i][2] = max(dp[i-1][2] ,nums[i] + dp[i-1][0]);
                 dp[i][1] = dp[i-1][1];
                if(dp[i-1][1])
                {
                    dp[i][0] =max(dp[i][0], nums[i] + dp[i-1][1]);
                    // dp[i][2] += dp[i][1];
                }
                if(dp[i-1][2]) dp[i][1] = max(dp[i-1][1], dp[i-1][2] + nums[i]); 
            }
        }
        int ans =0;
        for(int i=0; i<n; i++) ans = max(ans, dp[i][0]);
        return ans;
    }
};