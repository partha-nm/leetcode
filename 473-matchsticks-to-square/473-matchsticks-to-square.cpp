class Solution {
public:
    vector<int>a;
    bool solve(vector<int>&v, int pos)
    {
        if(pos == v.size())
        {
            int sum =0;
            for(int &x:a)sum+=x;
            if(sum == 0) return true;
            return false;
        }
        for(int &x:a)
        {
            if( x <  v[pos])  continue;
            x -= v[pos];
            if(solve(v, pos+1)) return true;
            x+=v[pos];
        }
        return false;
    }
    bool makesquare(vector<int>& v) 
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum % 4) return false;
        int edge = sum/4;
        sort(v.rbegin(), v.rend());
        a = {edge, edge , edge , edge};
        return solve(v, 0);
    }
};