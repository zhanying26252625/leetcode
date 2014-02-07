/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:

    vector<vector<int> > generateMatrix(int n) {
        
        if(n<=0)
            return vector<vector<int> >();
        
        vector<vector<int> > matrix(n,vector<int>(n,0));
        
        vector<pair<int,int> > dirs;
        dirs.push_back(pair<int,int>(0,1));
        dirs.push_back(pair<int,int>(1,0));
        dirs.push_back(pair<int,int>(0,-1));
        dirs.push_back(pair<int,int>(-1,0));
        
        int i = 0; 
        int j = 0;
        int cur = 0;
        
        for(int k = 1; k <= n*n; ++k){
            
            matrix[i][j] = k; //set value and mark the border
            
            pair<int,int> curDir = dirs[cur];
            int nextI = i + curDir.first;
            int nextJ = j + curDir.second;
            
            if( nextI>=matrix.size()||nextI<0 || 
                nextJ >=matrix[0].size() || nextJ < 0 || 
                matrix[nextI][nextJ]!=0){
                   cur = (cur+1)%dirs.size();
                   pair<int,int> curDir = dirs[cur];
                   nextI = i + curDir.first;
                   nextJ = j + curDir.second;
            }
            
            i = nextI;
            j = nextJ;
            
        }
        
        return matrix;
    }
    
};