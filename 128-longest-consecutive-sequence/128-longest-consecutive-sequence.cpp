class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0) return 0;
        set<int>st(nums.begin(), nums.end());
        vector<int>v(st.begin(), st.end());
        int ans =0, res =0;
        for(int i=1; i<v.size(); i++)
        {
            if(v[i] == v[i-1]) continue;
            if(v[i] - v[i-1] == 1) res++;
            else 
            {
                ans = max(ans, res);
                res =0;
            }
        }
        return max(ans,res) + 1;
    }
};