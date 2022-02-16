// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    int val =1;
    int ans =0;
    while(n>0)
    {
        int p = n%10;
        n = n/10;
        if(p==0)p=5;
        ans += val*p;
        val*=10;
    }
    return ans;
}