class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        int n = *max_element(nums.begin(), nums.end());
        vector<int>arr(n+1,0), dp(n+1,0);
        for(int &i:nums) arr[i]++;
        if(n == 1) return arr[1];
        dp[1] = arr[1]*1;
        dp[2] = max(arr[2]*2, arr[1]*1);
        for(int i=3; i<=n; i++)
        {
            dp[i] = max(i*arr[i]+dp[i-2], dp[i-1]);
        }
        return dp[n];
    }
};