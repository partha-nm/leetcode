class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
       int ans =0;
        for(auto x:accounts)
        {
            int res =0;
            for(int &y:x) res+=y;
            ans = max(ans,res);
        }
        return ans;
    }
};