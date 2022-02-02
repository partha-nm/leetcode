class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>ans;
        int n = s.size();
        int m = p.size();
        if(s.size() < p.size()) return ans;
        vector<int>v1(26,0),v2(26,0);
        for(int i=0; i<m; i++) 
        {
            int in1 = p[i] - 'a';
            int in2 = s[i] - 'a';
            v1[in1]++; v2[in2]++;
        }
        if(v1 == v2) ans.push_back(0);
        int f =0;
        for(int i=m; i<n; i++)
        {
            int in = s[i] - 'a';
            int out = s[f] - 'a';
             ++v2[in];
            --v2[out];
            if(v1 == v2) ans.push_back(f+1);
            f++;
        }
        return ans;
    }
};