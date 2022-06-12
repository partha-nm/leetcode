class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ps;
        ps.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            int p = nums[i] + ps[i-1];
            ps.push_back(p);
        }
        int ans =0, idx = -1;
        map<int, int>mp;
        for(int i=0; i<n; i++)
        {
            if(!mp.empty() && mp.find(nums[i]) != mp.end()) 
            {
                idx = max(idx, mp[nums[i]]);
                 int p = ps[i] - ps[idx];
                ans = max(ans, p);
            }
            else 
            {
                if(idx == -1) ans = max(ans , ps[i]);
                else
                {
                    ans = max(ans , ps[i] - ps[idx]);
                }
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};