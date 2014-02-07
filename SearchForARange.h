/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:

    vector<int> searchRange(int A[], int n, int target) {
        int l = lower_bound(A, n, target);
        int u = upper_bound(A, n, target);
        vector<int> res(2, -1);
        if(l!=u){
            res[0] = l;
            res[1] = u-1;
        }
        return res;
    }

    //[ )
    int lower_bound(int A[], int n, int target) {
        int l = 0, u = n;
        while (l < u) {
            int m = l+(u-l)/2;
            if (A[m] < target) l = m+1;
            else u = m;
        }
        return l;
    }

    //[ )
    int upper_bound(int A[], int n, int target) {
        int l = 0, u = n;
        while (l < u) {
            int m = l+(u-l)/2;
            if (A[m] <= target) l = m+1;
            else u = m;
        }
        return l;
    }
    
};


