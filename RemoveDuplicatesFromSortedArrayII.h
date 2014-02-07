/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

//duplicates are allowed at most twice
class Solution {
public:

    int removeDuplicates(int A[], int n) {
        
        int curLen = 0;

        int b = 0;
        int e = 1;
        
        while(b<n){
            
            while(e<n&&A[e]==A[b])
                ++e;
                
            int num = min(2,e-b);
            while(num-- > 0 )
                A[curLen++] = A[b];
                
            b = e;
            ++e;
        }
        
        return curLen;
    }
    
};