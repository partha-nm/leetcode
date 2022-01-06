class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
         map<int,int>m;
        for(auto &x:trips)
        {
             int p=x[0],q = x[1], r =x[2];
             m[q] += p;
             m[r] -= p;
        }
        int val=0;
        for(auto &x:m)
        {
            val +=x.second;
            if(val>capacity) return false;
        }
        return true;
    }
};