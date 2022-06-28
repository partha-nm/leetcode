class Solution {
public:
    int minDeletions(string s)
    {
        vector<int>cnt(26, 0);
        for(int i=0; i<s.size(); i++) 
        {
            int p = s[i] - 'a';
            cnt[p]++;
        }
        sort(cnt.begin(), cnt.end());
        int ans =0;
         for (int i = 24; i >= 0; i--) 
         {
            if(cnt[i] == 0) break;            
            if(cnt[i] >= cnt[i+1]){
                int prev = cnt[i];
                cnt[i] = max(0, cnt[i+1] -1);
                ans += prev - cnt[i]; 
            }
         }
        return ans;
    }
};