/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:

    void sortColors(int A[], int n) {
        if(n<=1)
            return;
            
        int cur = 0;
        int end0 = 0;
        int begin2 = n;
        
        while(cur<begin2){
            if(A[cur]==1){
                ++cur;
            }
            else if(A[cur]==0){
                swap(A[end0++],A[cur++]);
            }
            else{
                swap(A[--begin2],A[cur]);
            }
        }
    }
    
};