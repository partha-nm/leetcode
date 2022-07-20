class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
       map<char,vector<int>>mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]].push_back({i});
        }
        int cnt =0;
        for(auto &x:words)
        {
            bool flag = true;
            char c = x[0];
            int idx = -1;
            if(mp.find(c) == mp.end()) flag = false;
            else idx = mp[c].front();
            if(idx != -1)
            {
                for(int i=1; i<x.size(); i++)
                {
                    int val = -1;
                    c = x[i];
                    if(mp.find(c) == mp.end()) flag = false;
                    else
                    {
                        for(auto &y:mp[c])
                        {
                            if(y > idx){val = y; break;}
                        }
                    }
                    if(flag == false || val == -1){flag = false; break;}
                    else idx = val;
                }
            }
            if(idx != -1 && flag) cnt++;
        }
        return cnt;
    }
};
