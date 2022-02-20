class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) 
    {
       sort(v.begin(), v.end());
       int ans = v.size();
       int cmp = v[0][1], chk = v[0][0];
        for(int i=1; i<v.size(); i++)
        {
            int q = v[i][1];
             int p = v[i][0];
            if(cmp >= q) {ans--;}
            else if(chk == p){
                ans--;
                cmp = max(cmp, q);
            }
            else cmp = q, chk = p;
        }
        return ans;
    }
};