class Solution {
public:
    int rob(vector<int>& arr) 
    {
        int n = arr.size();
      if(n==1)
		return arr[0];

	int dp[n+1];

	dp[1] = arr[0];
	dp[2] = max(arr[0], arr[1]);

	for(int i=3; i<=n; i++)
	{
		dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
	}

	return dp[n];
    }
};