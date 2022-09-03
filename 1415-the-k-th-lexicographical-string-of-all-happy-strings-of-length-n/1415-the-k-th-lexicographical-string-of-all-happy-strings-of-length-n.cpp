class Solution {
public:
    vector<string>ans;
    string s = "abc";
    void solve(int n, int idx, string &temp)
    {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        for(auto &x:s)
        {
            if(idx == 0)
            {
                temp+=x;
                solve(n, idx+1, temp);
                temp.pop_back();
            }
            else if(x != temp[idx-1])
            {
                temp+=x;
                solve(n, idx+1, temp);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) 
    {
        int i = 0;
        string temp;
        solve(n,i, temp);
        sort(ans.begin(), ans.end());
        if(k > ans.size()) return "";
        return ans[k-1];
    }
};