class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
       set<int>s(nums.begin(),nums.end());
    vector<int>v(s.begin(),s.end());
    int count=1,res=1;
   for(int i=1;i<v.size();i++){
       if(v[i]==v[i-1]){
           continue;
       }
       else if(v[i]-v[i-1]==1){
           count++;
       }
       else{
           res=max(res,count);
           count=1;
       }
   }
    res=max(res,count);
    return res;
 }
};