class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
         int lcm = p*q/(__gcd(p,q));
         int ext = lcm/p, ref = lcm/q;
        if(ext%2 == 0 && ref % 2) return 0;
        if(ext%2 && ref % 2 == 0) return 2;
        return 1;
    }
};