class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
       int n=env.size();
       sort(env.begin(),env.end());
       vector<int>ans(n,1);
      ans[0] = 1;
       int res=1;
       for(int i=1;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(env[j][0]<env[i][0] && env[j][1]<env[i][1])
                   ans[i]=max(ans[i],1+ans[j]);
           }
           res=max(ans[i],res);
       }
      return(res);    
    }
};