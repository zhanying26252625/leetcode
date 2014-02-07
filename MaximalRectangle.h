/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:

    int maximalRectangle(vector<vector<char> > &matrix) {
        return maximalRectangle1(matrix);
    }
    
    
    //solution based on largestRectangleArea
    int maximalRectangle1(vector<vector<char> > &matrix) {
        if(matrix.size()==0||matrix[0].size()==0){
            return 0;
        }
        
        vector<vector<int> > area(matrix.size(),vector<int>(matrix[0].size(),0) );
        
        for(int j = 0; j<matrix[0].size();++j){
            for(int i = 0; i<matrix.size();++i){
                area[i][j]=(matrix[i][j] == '1');
            }
        }
        
        for(int j = 0; j<matrix[0].size();++j){
            for(int i = 1; i<matrix.size();++i){
                if(area[i][j]){
                    area[i][j] = area[i-1][j] + 1;
                }
            }
        }
        
        int max = 0;
        
        for(int i = 0; i<area.size();++i){
                
            max = std::max(max,largestRectangleArea(area[i]));
        }
        
        return max;
    }
    
    int largestRectangleArea(vector<int> &height) {
        
        if(height.size()==0)
            return 0;
            
        if(height.size()==1){
            return height[0];
        }
        
        vector<int> left(height.size(),0);
        stack<int> indexes;
        indexes.push(0);
        for(int i = 1 ; i < left.size(); ++i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                left[i] = i;
            }
            else{
                left[i] = i - indexes.top() - 1 ;
            }
            indexes.push(i);
        }
        
        vector<int> right(height.size(),0);
        indexes=stack<int>();
        indexes.push(height.size()-1);
        
        for(int i = right.size()-2; i >= 0 ; --i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                right[i] = right.size() - i - 1;
            }
            else{
                right[i] = indexes.top() - i - 1 ;
            }
            indexes.push(i);
        }
        
        int max = 0;
        for(int i = 0 ; i < height.size(); ++i){
            max = std::max(max, height[i]*(left[i]+1+right[i]) );
        }
        
        return max;
    }
    
};