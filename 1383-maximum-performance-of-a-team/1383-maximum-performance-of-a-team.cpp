class Solution {
public:
    int mod = 1e9 + 7;
    // static bool cmp(vector<int>v1, vector<int>)
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) 
    {
         vector<pair<int, int>>pp;
        for(int i=0; i<n; i++)
        {
            int a = ef[i] , b = sp[i];
            pp.push_back({a,b});
        }
        sort(pp.rbegin(), pp.rend());
        priority_queue<int, vector<int>, greater<int>>pq;
        long long ans =1, sum =0;
        for(int i=0; i<n; i++)
        {
            if(i+1 <= k)
            {
                sum=(sum + pp[i].second);
                pq.push(pp[i].second);
                long long val = (sum * pp[i].first);
                ans = max(ans, val);
            }
            else
            {
                sum=(sum + pp[i].second);
                pq.push(pp[i].second);
                sum-=pq.top();
                pq.pop();
                long long val = (sum * pp[i].first);
                ans= max(ans, val);
            }
        }
        return ans%(int)mod;
    }
};