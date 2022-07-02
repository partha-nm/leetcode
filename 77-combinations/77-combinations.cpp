class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(int curr, int n, int k)
    {
       if(curr) temp.push_back(curr);
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = curr+1; i<=n; i++)
        {
            solve(i, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        solve(0, n, k);
        return ans;
    }
};