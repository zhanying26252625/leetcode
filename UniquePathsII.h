/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0)
            return 0;
        
        if(obstacleGrid[0][0]||obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1])
            return 0;
           
        vector<vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),0) ); 
        
        dp[0][0]=1;
        
        for(int i = 0; i < dp.size(); ++i ){
            for(int j = 0; j < dp[0].size(); ++j){
                //not obstacle
                if(obstacleGrid[i][j]==0){
                    dp[i][j] += (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
};