class Solution {
public:
    vector<int> diffWaysToCompute(string ex) 
    {
        vector<int>res;
        int n =  ex.size();
        for(int i=0; i<n; i++)
        {
            char c = ex[i];
            if(c == '+' || c == '-' || c == '*')
            {
                vector<int>res1 = diffWaysToCompute(ex.substr(0,i));
                vector<int>res2 = diffWaysToCompute(ex.substr(i+1));
                for(auto n1:res1)
                {
                    for(auto n2:res2)
                    {
                        if(c == '+') res.push_back(n1+n2);
                        else if(c == '-') res.push_back(n1 - n2);
                        else res.push_back(n1*n2);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(ex));
        return res;
    }
};