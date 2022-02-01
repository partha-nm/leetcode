class Solution {
public:
    int maxProfit(vector<int>&v) {
        int ans =0;
        int mn = v[0];
        for(int i=1; i<v.size(); i++)
        {
            if(mn <v[i]) ans = max(ans, v[i]-mn);
            else mn = v[i];
            
        }
        return ans;
    }
};