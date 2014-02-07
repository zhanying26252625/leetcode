/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:

    int search(int A[], int n, int target) {
        
        int b = 0, e = n -1;
        
        while(b<=e){
            int m = b + (e-b)/2;
            if(A[m]==target){
                return m;
            }else if(A[m]>=A[b]){
                
                if(A[m]>=target&&target>=A[b]){
                    e = m - 1;
                }
                else{
                    b = m + 1;
                }
            }
            else{
                
                if(A[e]>=target&&target>=A[m]){
                    b = m + 1;
                }
                else{
                    e = m - 1;
                }
            }
        }
        
        return -1;
    }
    

};