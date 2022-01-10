class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int val = nums.size()-1;
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] + i >= val) val = i;
        }
        if(val == 0) return true;
        return false;
    }
};