class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
         vector<int>ans;
         queue<int>q;
        for(int i=1; i<=9; i++) q.push(i);
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            if(p >= low && p <= high) ans.push_back(p);
            if(p > high) break;
            int num = p%10;
            if(num < 9) {
                q.push(p * 10 + (num + 1));
            }
        
        }
        return ans;
    }
    
};