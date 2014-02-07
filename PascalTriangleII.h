/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> row(rowIndex+1,1);
        for(int r = 2; r<=rowIndex; ++r){
            for(int c = r-1; c >= 1 ; --c){
                row[c] += row[c-1];
            }
        }
        
        return row;
    }
};