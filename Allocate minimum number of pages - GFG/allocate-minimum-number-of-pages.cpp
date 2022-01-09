// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isValid(int md, int A[], int N, int M)
    {
        int std = 1, val=0;
        for(int i=0; i<N; i++)
        {
            val+=A[i];
            if(val>md)
            {
                val=A[i];
                std++;
            }
            if(std>M) return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
         int sum = 0, mx = INT_MIN;
         for(int i=0; i<N; i++)mx = max(mx,A[i]), sum+=A[i];
         int res = -1;
         int lo = mx, high = sum;
         while(lo<=high)
         {
             int md = lo + (high-lo)/2;
             if(isValid(md, A, N, M))
             {
                 res = md;
                 high = md-1;
             }
             else lo = md+1;
         }
         return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends