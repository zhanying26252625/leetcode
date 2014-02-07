/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int> v;
        if(matrix.size()==0||matrix[0].size()==0)
            return v;
            
        vector<pair<int,int> > dirs;
        dirs.push_back(pair<int,int>(0,1));
        dirs.push_back(pair<int,int>(1,0));
        dirs.push_back(pair<int,int>(0,-1));
        dirs.push_back(pair<int,int>(-1,0));
        
        int N = matrix.size() * matrix[0].size();
        int i = 0; 
        int j = 0;
        int cur = 0;
        
        for(int k = 0; k < N; ++k){
            
            v.push_back(matrix[i][j]);
            matrix[i][j] = 0; //mark the border
            
            pair<int,int> curDir = dirs[cur];
            int nextI = i + curDir.first;
            int nextJ = j + curDir.second;
            
            if( nextI>=matrix.size()||nextI<0 || 
                nextJ >=matrix[0].size() || nextJ < 0 || 
                matrix[nextI][nextJ]==0){
                   cur = (cur+1)%dirs.size();
                   pair<int,int> curDir = dirs[cur];
                   nextI = i + curDir.first;
                   nextJ = j + curDir.second;
            }
            
            i = nextI;
            j = nextJ;
            
        }
        
        return v;
    }
    
};