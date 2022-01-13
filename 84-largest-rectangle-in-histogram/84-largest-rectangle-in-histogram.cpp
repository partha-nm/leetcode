class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
       stack<int>s;
        int res =0, curr = 0;
        for(int i=0; i<h.size(); i++)
        {
            while(!s.empty() && h[s.top()] >= h[i]) 
            {
                int tp = s.top(); s.pop();
                curr = h[tp]*(s.empty() ? i : i-s.top()-1);
                res = max(res,curr);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int tp = s.top(); s.pop();
            curr = h[tp]*(s.empty()?h.size():h.size()-s.top()-1);
            res = max(res,curr);
        }
        return res;
    }
};