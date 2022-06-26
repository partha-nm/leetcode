class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(int sz, vector<int>&nums)
    {
        if(sz == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == INT_MIN) continue;
            int val = nums[i];
            temp.push_back(val);
            nums[i] = INT_MIN;
            solve(sz-1, nums);
            nums[i] = val;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
       int sz = nums.size();
        solve(sz, nums);
        return ans;
    }
};