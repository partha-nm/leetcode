class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) 
    {
        for(int i=0; i<m.size(); i++)
        {
            int low = 0, high = m[i].size()-1;
            if(m[i][low] <= target && m[i][high] >= target)
            {
            
               while(low  <= high)
               {
                int mid = low + (high - low)/2;
                if(m[i][mid] == target) return true;
                else if(m[i][mid] < target) low = mid+1;
                else high = mid-1;
               }   
            }
        }
        return false;
    }
};