/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int t = m + n;
        if(!t)
            return 0.0;
            
        if(t%2)
            return (double)findkth(A,m,B,n,t/2+1);
        else
            return ( findkth(A,m,B,n,t/2+1) + findkth(A,m,B,n,t/2) ) / 2.0 ;
    }
    
    double findkth(int A[], int m, int B[], int n, int k){
        
        if(m>n)
            return findkth(B,n,A,m,k);
        if(m==0)
            return B[k-1];
        if(k==1)
            return min(A[0],B[0]);
            
        int a = min(k/2,m);
        int b = k - a;
        
        if(A[a-1]==B[b-1])
            return B[b-1];
        else if(A[a-1]<B[b-1])
            return findkth(A+a,m-a,B,n,k-a);
        else
            return findkth(A,m,B+b,n-b,k-b);
    }
 
    
};





