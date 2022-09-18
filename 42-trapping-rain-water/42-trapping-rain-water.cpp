class Solution {
public:
int trap(vector<int>& A) {
    int max=0,sum=0;
    vector<int> l(A.size(),0);
    
    for(int i=A.size()-1;i>=0;i--)
    {   if(A[i]>max) max=A[i];
        l[i]=max;
    }
    
    max=0;
    for(int i=0;i<A.size();i++)
    {   if(A[i]>max) max=A[i];
        sum=sum+min(l[i],max)-A[i];
    }
return sum;
}
};