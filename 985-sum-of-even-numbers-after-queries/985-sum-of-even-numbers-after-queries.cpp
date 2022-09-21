class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) 
    {
       int sum = 0;
        int n = nums.size();
        vector<int>ans;
        vector<bool>track(n, false);
        for(int i=0; i<n;  i++)
        {
            if(nums[i] % 2 == 0) {sum+=nums[i]; track[i] = true;}
        }
        
        for(int i=0; i<q.size(); i++)
        {
            int a = q[i][0], b = q[i][1];
            if(track[b])
            {
                sum-=nums[b];
                nums[b]+=a;
            }
            else
            {
                nums[b]+=a;
            }
            if(nums[b] % 2 == 0 ){sum+=nums[b]; track[b] = true;}
            else track[b] = false;
            ans.push_back(sum);
        }
        return ans;
    }
};