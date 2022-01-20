class Solution {
public:
    bool isValid(int mid, vector<int>&piles, int h)
    {
        long long int res=0;
        for(int i=0; i<piles.size(); i++)
        {
            if(piles[i] % mid == 0) res += piles[i]/mid;
            else res += piles[i]/mid + 1;
            if(res > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
         int low = 1;
         int high = *max_element(piles.begin(), piles.end());
         int ans = high;
    
         while(low<=high)
         {
             int mid = low + (high-low)/2;
             if(isValid(mid, piles, h))
             {
                 ans = mid;
                 high = mid-1;
             }
             else low = mid+1;
         }
        return ans;
    }
};