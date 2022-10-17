class Solution {
public:
    bool checkIfPangram(string s) 
    {
        vector<int>v(26, 0);
        int val =0;
        for(int i=0; i<s.size(); i++)
        {
            int p = s[i] - 'a';
            if(!v[p]) val++;
            v[p]++;
        }
        return val == 26;
    }
};