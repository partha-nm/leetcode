class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int chk = 0;
        for(int i=0; i<nums.size(); i++) chk = chk^nums[i];
        return chk;
    }
};