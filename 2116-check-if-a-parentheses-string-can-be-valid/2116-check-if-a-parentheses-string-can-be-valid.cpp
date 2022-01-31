class Solution {
public:
    bool canBeValid(string s, string l) 
    {
        int n = s.size();
        if(n&1) return false;
        int cnt =0;
        for(int i=0; i<n; i++)
        {
            if(l[i] == '0' || s[i] == '(') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
         cnt =0;
        for(int i=n-1; i>=0; i--)
        {
            if(l[i] == '0' || s[i] == ')') cnt++;
            else cnt--;
            if(cnt <0) return false;
        }
        return true;
    }
};