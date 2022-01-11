class StockSpanner {
      stack<int>s;
    vector<int>v;
public:
    StockSpanner() 
    {
    }
    int next(int price) 
    {
        v.push_back(price);
        if(v.size() == 1){s.push(0); return 1;}
        while(s.size()!=0 && v[s.top()] <= v.back()) s.pop();
        int sp = s.empty()?v.size() : v.size() - s.top()-1;
        s.push(v.size()-1);
        return sp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */