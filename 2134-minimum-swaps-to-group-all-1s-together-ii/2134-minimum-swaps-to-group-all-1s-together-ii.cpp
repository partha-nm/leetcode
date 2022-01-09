class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int cnt =0;
        for(int &i:nums)if(i==1)cnt++;
        int n=nums.size();
        for(int i=0; i<n; i++) nums.push_back(nums[i]);
        n = nums.size();
        int sum=0;
        for(int i=0; i<cnt; i++)sum+=nums[i];
        int ans = cnt-sum;
        for(int i=cnt; i<n; i++)
        {
            sum+=nums[i]-nums[i-cnt];
            ans = min(ans,cnt-sum);
        }
        return ans;
    }
};