class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       int ans =0;
       map<int,int>m;
    for(int &x:nums) m[x]++;
        for(auto &x:m)
        {
            if(k==0)
            {
                if(x.second > 1) ans++;
            }
                else 
                {
                    int p = x.first+k;
                    if(m.find(p) != m.end()) ans++;
                }
            
        }
        return ans;
    }
};