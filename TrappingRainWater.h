/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

class Solution {
public:

    int trap(int A[], int n) {
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int max = 0;
        for(int i = 0; i < n; ++i){
            max = std::max(max,A[i]);
            left[i]=max;
        }
        
        max = 0;
        for(int i = n-1; i >- 0; --i){
            max = std::max(max,A[i]);
            right[i]=max;
        }
        
        int water = 0 ;
        
        for(int i = 1; i < n-1; ++i){
            water += min(left[i],right[i]) - A[i];
        }
     
        return water;   
    }
};