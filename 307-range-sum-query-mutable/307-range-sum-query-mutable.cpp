class NumArray {
public:
    vector<int>v;
    int sum =0;
    NumArray(vector<int>& nums) {
        v = nums;
        for(int i=0; i<v.size(); i++) sum+= nums[i];
    }
    
    void update(int index, int val) 
    {
        sum-=v[index];
        v[index] = val;
        sum+=v[index];
    }
    
    int sumRange(int left, int right) 
    {
       int res = sum;
        for(int i=0; i<left; i++) res-=v[i];
        for(int i=right+1; i<v.size(); i++) res-=v[i];
        return res;
    }
};

