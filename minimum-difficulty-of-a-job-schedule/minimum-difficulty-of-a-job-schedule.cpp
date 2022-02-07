class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(n < d)  return -1;
        vector<vector<int>>dp(n, vector<int>(d+1, INT_MAX));
        dp[n-1][d] = job[n-1];
        for(int i=n-2; i>= 0; i--) dp[i][d] = max(job[i], dp[i+1][d]);
       for (int day = d - 1; day > 0; day--) {
            for (int i = day - 1; i < n - (d - day); i++) {
                int hardest = 0;
                for (int j = i; j < n - (d - day); j++) {
                    hardest = max(hardest, job[j]);
                    dp[i][day] = min(dp[i][day], hardest + dp[j + 1][day + 1]);
                }
            }
        }
        return dp[0][1];
    }
};