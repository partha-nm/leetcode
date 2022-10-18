//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
	     vector<int>ans;
	     int p=0, q=0, r=0, s= 0;
	     for(int i=0; i<2*n-1; i++)
	     {
	        if(p < n)
	        {
	            r = p; q = s;
	            while(r>=0 && q < n)ans.push_back(A[q++][r--]);
	            p++;
	        }
	        else
	        {
	            s++;
	            q = s;
	            r = n-1;
	            //cout<<i<<" "<<endl;
	            while(r>=0 && q<n) ans.push_back(A[q++][r--]);
	        }
	     }
	     return ans;
	     
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends