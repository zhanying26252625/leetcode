/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
    
public:

    int lower_bound(const vector<int>& v, int target){
        int l = 0;
        int h = v.size();
        while(l<h){
            int m = l + (h-l)/2;
            if(v[m]==target){
                return m;
            }
            else if(v[m]>target){
                h = m ;
            }
            else{
                l = m + 1;
            }
        }
        
        return h;
    }
    
    int searchInsert(int A[], int n, int target) {
        vector<int> v(A,A+n);
        return lower_bound(v,target);
    }
    
};