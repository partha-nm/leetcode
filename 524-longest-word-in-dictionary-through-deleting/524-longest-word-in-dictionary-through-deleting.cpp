class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        string ans= "";
        int len = 0;
        for(auto &x:dictionary)
        {
            int n = s.size(), t = x.size();
            int i = 0, j = 0;
            while(i< n && j < t)
            {
                if(s[i] == x[j]) j++;
                i++;
            }
            if(j == t)
                {
                    if(j > len)
                    {
                        ans = x;
                        len = max(len, j);
                    }
                    if(j == len)
                    {
                        ans = min(ans, x);
                    }
                }
        }
        return ans;
    }
};