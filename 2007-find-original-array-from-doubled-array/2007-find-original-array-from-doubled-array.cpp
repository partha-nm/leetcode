class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        map<int, int>mp;
        for(int &i:changed) mp[i]++;
        sort(changed.begin(), changed.end());
        vector<int>ans;
        for(int i=0; i<changed.size(); i++)
        {
            int p = changed[i], q = 2 * changed[i];
            if(p == 0 && mp[p] > 0)
            {
                if(mp[p] % 2 == 0)mp[p]-=2;
                else return {};
                
                ans.push_back(p);
            }
            else if(mp[p] > 0)
            {
                if(mp[q] > 0) mp[q]--;
                else return {};
                ans.push_back(p);
                mp[p]--;
            }
        }
        return ans;
    }
};