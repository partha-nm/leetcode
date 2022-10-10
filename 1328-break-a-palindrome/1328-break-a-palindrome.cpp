class Solution {
public:
    string breakPalindrome(string s) 
    {
        if(s.size() == 1) return "";
        int j = s.size() -1;
        for(int i=0; i<s.size()/2; i++)
        {
            if(s[i] != s[j]) return s;
            if(s[i] != 'a') 
            {
                s[i] = 'a';
                return s;
            }
            j--;
        }
        s.back() = 'b';
        return s;
    }
};