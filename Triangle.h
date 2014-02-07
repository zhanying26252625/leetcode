/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:

    int minimumTotal(vector<vector<int> > &triangle) {
        
        int row = triangle.size();
        
        vector<int> v(row+1,0);
        
        for(int i = row-1; i>=0; --i){
            for(int j = 0 ; j < row; ++j){
                v[j] = triangle[i][j] + min(v[j],v[j+1]);
            }
        }
        
        return v[0];
    }
    
};