class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        sum -= x;
        // cout<<sum<<endl;
        if(sum == 0) return nums.size();
        if(sum < 0) return -1;
        int ans = -1;
        int start = 0, end  =0, curr = nums[0];
        while(end < nums.size())
        {
            if(curr < sum)
            {
                end++;
                if(end == nums.size()) break;
                curr+=nums[end];
            }
            else if(curr > sum)
            {
                curr-=nums[start];
                start++;
            }
            else if(curr == sum)
            {
                int val = end-start+1;
                ans = max(ans , val);
                curr-=nums[start];
                start++;
            }
        }
        if(ans == -1) return -1;
        return nums.size() -ans;
    }
};