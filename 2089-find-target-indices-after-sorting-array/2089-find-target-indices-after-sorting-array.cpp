class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lo == nums.size() || nums[lo] != target) return {};
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
        if(lo == hi) return {lo};
        for(int i=lo; i<=hi; i++) ans.push_back(i);
        return ans;
    }
};