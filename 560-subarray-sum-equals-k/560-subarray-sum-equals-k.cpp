class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
       int ans =0;
        map<int,int>m;
        int p=0;
        m[0]++;
        for(int &x:nums)
        {
            p+=x;
            ans+= m[p-k];
            m[p]++;
        }
        return ans;
    }
};