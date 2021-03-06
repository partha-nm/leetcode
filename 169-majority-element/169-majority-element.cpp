class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res =0, count =0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[res] == nums[i]) count++;
            else count--;
            if(count ==0)
            {
                res = i; count++;
            }
        }
        return nums[res];

    }
};