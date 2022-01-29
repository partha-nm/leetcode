class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
       stack<int>s;
        int curr = 0, res =0;
        int n = h.size();
        for(int i=0; i<n; i++)
        {
            while(!s.empty() && h[s.top()] >= h[i])
            {
                int tp = s.top(); s.pop();
                curr = h[tp]*(s.empty()?i : i-1-s.top());
                res = max(curr , res);
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int tp =  s.top(); s.pop();
            curr = h[tp] * (s.empty() ? n : n-s.top()-1);
            res = max(curr, res);
        }
        return res;
    }
};