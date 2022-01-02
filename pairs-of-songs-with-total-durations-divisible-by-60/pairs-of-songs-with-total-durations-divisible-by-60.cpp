class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& t) 
    {
        map<int,int>m;
        int ans =0;
        for(int &i:t)
        {
            int p = (60- i%60)%60; 
            ans+= m[p];
            m[i%60]++;
        }
      return ans;
    }
};