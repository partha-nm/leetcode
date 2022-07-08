class Solution {
public:

    vector<int>temp;
     vector<vector<int>>ans;
    void solve(int idx, vector<int>v, int target)
    {
       if(target == 0)
       {
           ans.push_back(temp);
           return;
       }
        for(int i=idx; i<v.size(); i++)
        {
            if(i >idx && v[i] == v[i-1]) continue;
            if(target >=v[i])
            {
                temp.push_back(v[i]);
                solve(i+1, v, target - v[i]);
                temp.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) 
    {
        sort(c.begin(), c.end());
        solve(0,c,target); 
        return ans;
    }
};