class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        int cm = arr.size()/2;
        int ans =0;
        map<int,int>mp;
        for(int &x:arr)mp[x]++;
        vector<int>val;
        for(auto &x:mp) val.push_back(x.second);
        sort(val.rbegin(), val.rend());
        int sum =0;
        for(int i=0; i<val.size(); i++)
        {
            sum+=val[i];
            ans++;
            if(sum >= cm) return ans;
        }
        return ans;
    }
};