class Solution {
public:
    set<vector<int>>st;
    vector<int>temp;
    void solve(vector<int>&nums, int n)
    {
        if(n==0)
        {
            st.insert(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == INT_MAX) continue;
            int val = nums[i];
            nums[i] = INT_MAX;
            temp.push_back(val);
            solve(nums, n-1);
            nums[i] = val;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        solve(nums, n);
        vector<vector<int>>ans;
        for(auto &x:st) ans.push_back(x);
        return ans;
    }
};