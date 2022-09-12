class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {
        int ans =0;
        sort(t.begin(), t.end());
        int score = 0;
        int i =0,j = t.size() -1;
        while(i <= j)
        {
            if(t[i] <= power)
            {
                power-=t[i];
                score++;
                i++;
            }
            else if(score > 0)
            {
                power+=t[j];
                score--;
                j--;
            }
            else break;
            ans = max(ans, score);
        }
        return ans;
    }
};