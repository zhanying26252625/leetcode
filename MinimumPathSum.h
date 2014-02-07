/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int N = grid.size();
        if(!N)
            return 0;
        int M = grid[0].size();
        if(!M)
            return 0;
            
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(i==0&&j==0)
                    continue;
                grid[i][j] = min(i>0?grid[i-1][j]:INT_MAX , j>0?grid[i][j-1]:INT_MAX) + grid[i][j];
            }
        }
        
        return grid[N-1][M-1];
    }
};