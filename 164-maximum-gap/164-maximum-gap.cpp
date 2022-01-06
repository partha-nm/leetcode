class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        if(nums.size() <2) return 0;
        int n = nums.size();
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int interval =((mx-mn)+n-2)/(n-1);
        vector<int>min_buc(n-1, INT_MAX), max_buc(n-1, INT_MIN);
        for(int i=0;  i<n; i++)
        {
            if(nums[i] == mn || nums[i] == mx) continue;
            int idx = (nums[i]-mn)/interval;
            min_buc[idx] = min(min_buc[idx],nums[i]);
            max_buc[idx] = max(max_buc[idx], nums[i]);
        }
        int prev = mn;
        int gap=0;
        for(int i=0; i<n-1; i++)
        {
            if(max_buc[i] == INT_MIN) continue;
            gap = max(gap, min_buc[i]-prev);
            prev = max_buc[i];
        }
        gap = max(gap, mx-prev);
            return gap;
    }
};