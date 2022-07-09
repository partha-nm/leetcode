class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>>pq;
        int n = nums.size();
        vector<int>dp(n, 0);
        if(n ==  1) return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[0] + nums[1];
        pq.push({dp[0], 0}); 
        pq.push({dp[1],1});
        for(int i=2; i<=min(n-1,k); i++)
        {
            dp[i] = pq.top().first+nums[i];
            pq.push({dp[i], i});
        }
        for(int i=k+1; i<n; i++)
        {
            int p = i - k;
            while(!pq.empty() && pq.top().second < p)
            {
                pq.pop();
            }
            dp[i] = pq.top().first + nums[i];
            pq.push({dp[i], i});
        }
        return dp[n-1];
    }
};