class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1,0));
        for(int i=m-1; i>=0; i--)
        {
            for(int left=i; left>=0; left--)
            {
                int val = multipliers[i];
                int right = n-1-(i-left);
                dp[i][left] = max(nums[left]*val + dp[i+1][left+1], nums[right]*val+dp[i+1][left]);
            }
        }
        return dp[0][0];
    }
};