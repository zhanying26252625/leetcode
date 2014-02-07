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
    
};