class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) 
    {
       map<int, int>mp;
        for(int i=0; i<num.size(); i++)
        {
            int val = target - num[i];
            if(!mp.empty() && mp.find(val) != mp.end()) return {mp[val], i+1};
            else mp[num[i]] = i+1;
        }
        for(auto &x:mp)  cout<<x.first<<" "<<x.second<<endl;
        return {-1, -1};
    }
};