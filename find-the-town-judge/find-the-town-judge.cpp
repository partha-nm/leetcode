class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        int p =  trust.size();  
        cout<<p<<endl;
        vector<int>in(n+1,0), out(n+1,0);
        for(auto x:trust)
        {
            in[x[1]]++;
            out[x[0]]++;
        }
        for(int &i:in) cout<<i<<" ";
        for(int i=1;i<=n; i++) 
        {
            if(out[i] == 0)
            {
                if(in[i] == n-1) return i;
                else return -1;
            }
        }
        return -1;
    }
};