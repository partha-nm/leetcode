class Solution {
public:
    
    int solve(string &word1, string &word2, int i , int j, vector<vector<int>>&dp)
    {
        if(word1.size() == i && word2.size() == j) return 0;
        
        if(word1.size() == i)return word2.size() - j;
        if(word2.size() == j) return word1.size() -i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
       return dp[i][j] = 1 + min({
           solve(word1, word2, i+1, j+1, dp),
           solve(word1, word2, i, j+1, dp),
           solve(word1, word2, i+1, j, dp)
       });
    }
    int minDistance(string word1, string word2) 
    {
        int i=0, j =0;
        int n = word1.size(), m = word2.size();
        if(n ==0 && m == 0) return 0;
        if(n == 0) return m;
        if(m ==0) return n;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        solve(word1, word2, i, j, dp);
         
        return dp[0][0];
    }
};