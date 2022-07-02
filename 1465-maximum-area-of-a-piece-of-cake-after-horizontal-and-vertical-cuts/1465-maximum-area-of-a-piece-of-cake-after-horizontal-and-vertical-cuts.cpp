class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
         hc.push_back(0); hc.push_back(h);
         vc.push_back(0); vc.push_back(w);
         int hMax =0, vMax = 0;
         sort(hc.begin(), hc.end()); sort(vc.begin(), vc.end());
         for(int i=0; i<hc.size()-1; i++) hMax = max(hMax, abs(hc[i] - hc[i+1]));
         for(int i=0; i<vc.size()-1; i++) vMax = max(vMax, abs(vc[i] - vc[i+1]));
         return (1LL*hMax*vMax)%1000000007;
    }
};