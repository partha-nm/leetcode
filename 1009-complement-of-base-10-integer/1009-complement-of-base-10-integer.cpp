class Solution {
public:
    int bitwiseComplement(int n) 
    {
           if(n==0) return 1;
          for(long long int i=1; i<=n; i*=2) n = n^i;
          return n;
    }
};