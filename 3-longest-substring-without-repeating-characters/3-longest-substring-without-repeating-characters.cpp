class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       int n = s.size();
       map<char, int>m;
        int counter =0, end =0, begin=0, d =0;
        while(end < n)
        {
            char cp = s[end];
            m[cp]++;
            if(m[cp] > 1) counter++;
            end++;
            while(counter > 0)
            {
                char ch = s[begin];
                if(m[ch] > 1)  counter--;
                m[ch]--;
                begin++;
            }
            d = max(end-begin, d);
        }
        return d;
    }
};