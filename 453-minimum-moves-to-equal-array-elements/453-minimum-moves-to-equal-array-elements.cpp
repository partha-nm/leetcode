class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
       int ans =0;
       int mn = *min_element(nums.begin(), nums.end());
       for(int i=0; i<nums.size(); i++) ans+=nums[i] - mn;
        return ans;
    }
};