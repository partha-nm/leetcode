class Solution {
public:
    bool isValid(vector<int>w, int md, int days)
    {
        int sum =0, cnt =1;
        for(int i=0; i<w.size(); i++)
        {
            sum+=w[i];
            if(sum > md) 
            {
                sum = w[i];
                cnt++;
            }
            if(cnt > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& w, int days) 
    {
        int mx = *max_element(w.begin(),w.end());
        int sum = accumulate(w.begin(),w.end(),0);
        int lo = mx, hi =  sum;
        int res =-1;
        while(lo <= hi)
        {
            int md = lo + (hi-lo)/2;
            if(isValid(w,md,days))
            {
                res = md; hi = md-1;
            }
            else lo = md+1;
        }
        return res;
    }
};