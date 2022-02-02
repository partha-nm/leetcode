class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n = s.size();
        int m1 = t.size();
        if(n < m1) return "";
        map<char,int>m;
        for(auto &x:t) m[x]++;
        int counter = m.size();
        int begin =0, end=0, head =0;
        int len = INT_MAX;
        while(end < n)
        {
            char cp = s[end];
            if(m.find(cp) != m.end())
            {
                m[cp]--;
                if(m[cp] == 0) counter--;
            }
            end++;
            while(counter == 0)
            {
                char ch = s[begin];
                if(m.find(ch) != m.end())
                {
                    m[ch]++;
                    if(m[ch] > 0) counter++; 
                }
                if(end- begin < len)
                {
                    len = end - begin;
                    head = begin;
                }
                begin++;
            }
        }
        cout<<head<<" "<<len<<endl;
        if(len == INT_MAX) return "";
        return s.substr(head, len);
    }
};