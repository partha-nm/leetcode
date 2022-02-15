class Solution {
public:
    void solve(vector<string>&ans, string op, int open, int close)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(op);
            return;
        }
        if(open != 0)
        {
            string op1 =  op;
            op1.push_back('(');
            solve(ans, op1, open-1, close);
        }
        if(open < close)
        {
            string op2 = op;
            op2.push_back(')');
            solve(ans, op2, open, close-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open =n, close = n;
        string op ="";
        solve(ans, op, open, close);
        return ans;
    }
};