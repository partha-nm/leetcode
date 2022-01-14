class Solution {
public:
    int myAtoi(string s) {
        
        int i=0;
       long long int ans =0;
        while(s[i] == ' ') i++;
        
        int sign = 1;
        if(s[i] == '-'){sign = -1; i++;}
        else if(s[i] == '+') i++;
        
        while(s[i] >= '0' && s[i] <= '9')
        {
            ans = ans*10 + (s[i] -'0')*sign;
            i++;
            if(ans > INT_MAX) return INT_MAX;
            if(ans < INT_MIN) return INT_MIN;
        }
        return ans;
    }
};