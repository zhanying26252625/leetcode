/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:

    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        int N = matrix.size();
        for (int i = 0; i <= N/2; i++) {
            int first = i, last = N-i-1;
            for (int j = first; j < last; j++) {
                int top = matrix[first][j], offset = j-first;
                matrix[first][j] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[j][last];
                matrix[j][last] = top;
            }
        }  
    }
	
	/*
	void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        if(N<=1)
            return;
        
        for(int i = 0; i < N/2; ++i){
            int b = i;
            int e = N-i-1;
            for(int l = 0; b+l<e ; ++l){
                int tmp = matrix[b][b+l];
                matrix[b][b+l] = matrix[e-l][b];
                matrix[e-l][b] = matrix[e][e-l];
                matrix[e][e-l] = matrix[b+l][e];
                matrix[b+l][e] = tmp;
            }
        }
        return;
        
        
    }
	*/
    
};