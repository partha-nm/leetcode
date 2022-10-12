class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
      
        for(int i=2; i<nums.size(); i++){
            int a = nums[i-2];
            int b = nums[i-1];
            int c = nums[i];
            float s = (float)(a+b+c)/2;
            if(s>a and s>b and s>c){
                return s*2;
            }
        }
        return 0;
    }
};