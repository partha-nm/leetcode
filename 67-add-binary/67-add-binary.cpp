class Solution {
public:
    string addBinary(string a, string b) 
    {
        int m=a.size()-1, n = b.size()-1;
        string sum;
        int carry =0;
        while(m >= 0 ||  n>=0 || carry > 0)
        {
            if(m>=0)
            {
                carry += a[m]-'0';
                m--;
            }
            if(n>=0)
            {
                carry += b[n]-'0';
                n--;
            }
            sum += (carry%2)+'0';
            carry = carry/2;
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};