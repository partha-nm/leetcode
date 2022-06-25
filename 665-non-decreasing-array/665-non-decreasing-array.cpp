class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int mx = INT_MIN, cnt =0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < mx) {cnt++; if(i == 1 || nums[i-2] <= nums[i]) mx = nums[i];}
            else mx = max(nums[i], mx);
            if(cnt > 1) return false;
        }
       return true;
    }
};