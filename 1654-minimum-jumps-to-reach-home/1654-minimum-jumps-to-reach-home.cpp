class Solution {
public:
    int minimumJumps(vector<int>& f, int a, int b, int x) 
    {
        map<int,int>mp;
        for(auto &x: f) mp[x] = 3;
        queue<pair<int,int>>q;
        q.push({0,0});
        int ans =0;
        mp[0] = 1;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto curr = q.front();
                q.pop();
                int p = curr.first + a;
                int r = curr.first - b;
                if(curr.first == x) return ans;
                if( p < 10000 && mp[p] < 2)
                {
                    mp[p] = 2;
                    q.push({p, 0});
                }
                if(r > 0 && mp[r] == 0 && curr.second == 0)
                {
                    mp[r] = 1;
                    q.push({r, 1});
                }
            }
            ans++;
        }
        return -1;
        
    }
};