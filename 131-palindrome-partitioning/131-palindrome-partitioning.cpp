class Solution {
public:
    bool ispalindrome(string s, int strt , int end)
    {
        while(strt<=end)
        {
            if(s[strt++] != s[end--]) return false;
        }
        return true;
    }
    void dfs(int idx, string &s, vector<vector<string>>&ans, vector<string>&path)
    {
        if(idx == s.size())
        {
             ans.push_back(path);
            return;
        }
        for(int i=idx; i<s.size(); i++)
        {
            if(ispalindrome(s,idx,i))
            {
                path.push_back(s.substr(idx,i-idx+1));
                dfs(i+1, s, ans, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        if(s.empty()) return ans;
        vector<string>path;
        dfs(0,s,ans,path);
        return ans;
    }
};