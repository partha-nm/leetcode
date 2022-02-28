class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
       vector<string>ans;
        if(nums.empty()) return ans;
       int first = nums[0], last=nums[0];
       for(int i=1; i<nums.size(); i++)
       {
            if(nums[i] == nums[i-1]+1)
            {
                last = nums[i];
            }
            else
            {
                string p = to_string(first);
                string q = to_string(last);
                if(first == last) ans.push_back(p);
                else{string val = p+"->"+q; ans.push_back(val);}
                first = nums[i], last = nums[i];
            }
       }
          string p = to_string(first);
                string q = to_string(last);
                if(first == last) ans.push_back(p);
                else{string val = p+"->"+q; ans.push_back(val);}
        return ans;
    }
};