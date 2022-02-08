class Solution {
public:
    bool countDigit(int n)
    {
        int p = log10(n)+1;
        if(p == 1) return true;
        return false;
    }
    int addDigits(int num) 
    {
        if(num == 0) return num;
        while(!countDigit(num))
        {
            string s = to_string(num);
            num =0;
            for(int i=0; i<s.size(); i++)
            {
                num+= s[i]-'0';
            }
        }
        return num;
    }
};