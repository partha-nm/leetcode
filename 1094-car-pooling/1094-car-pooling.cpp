class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
         vector<int>v(1001, 0);
        int mx= INT_MIN;
        for(auto &x:trips)
        {
             int p=x[0],q = x[1], r =x[2];
             v[q] += p;
             v[r] -= p;
            mx = max(mx, max(q,r));
        }
        int val=0;
       for(int i=0; i<=mx; i++)
       {
           val+=v[i];
           if(capacity < val) return false;
       }
        return true;
    }
};