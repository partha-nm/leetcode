class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>m{{0,-1}};
        int sum=0, ans =0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0) sum--;
            else sum++;
            if(m.count(sum)) ans = max(ans, i-m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};