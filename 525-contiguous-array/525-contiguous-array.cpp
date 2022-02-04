class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>v(2*n+1, INT_MIN);
        int sum =0, ans =0;
        v[n] = -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0) sum--;
            else sum++;
            if(v[n+sum] >= -1) ans = max(ans, i-v[n+sum]);
            else v[n+sum] = i;
        }
        return ans;
    }
};