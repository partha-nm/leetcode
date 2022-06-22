class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>pq(nums.begin(), nums.end());
        int ans = -1;
        while(pq.size() > 0 && k > 0)
        {
            ans = pq.top();
            k--;
            pq.pop();
        }
        return ans;
    }  
};