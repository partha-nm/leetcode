class Solution {
public:
    vector<int> targetIndices(vector<int>& v, int target) 
    {
        vector<int>ans;
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++) if(v[i] == target) ans.push_back(i);
        if(ans.size() == 0) return {};
        return ans;
    }
};