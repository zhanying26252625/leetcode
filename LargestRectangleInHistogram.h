/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:

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








