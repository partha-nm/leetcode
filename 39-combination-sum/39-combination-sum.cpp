class Solution {
public:
    void solve(vector<int>c, int index, vector<vector<int>>&ans, vector<int>temp, int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
         if(index >= c.size()) return;
        if(c[index] <= target)
        {
            temp.push_back(c[index]);
            solve(c,index,ans,temp, target-c[index]);
            temp.pop_back();
        }
        solve(c,index+1,ans,temp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        set<int>s;
        for(int &i:c)s.insert(i);
        c.clear();
        for(auto &x:s) c.push_back(x);
        solve(c,0,ans, temp, target);
        return ans;
    }
};