class Solution {
public:
    int countSet(int n)
    {
        int res =0;
        while(n>0)
        {
            n = n & (n-1);
            res++;
        }
        return res;
    }
    vector<int> countBits(int n) 
    {
        vector<int>ans;
        for(int i=0; i<=n; i++)
        {
            int p = countSet(i);
            ans.push_back(p);
        }
        return ans;
    }
};