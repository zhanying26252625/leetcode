/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:

    void nextPermutation(vector<int> &num) {
        
        if(num.size()==0||num.size()==1)
            return;
        
        int i = num.size()-2;
        for( ; i>=0; --i){
            if(num[i]<num[i+1])
                break;
        }
        
        //rollback
        if(i==-1){
            reverse(num.begin(),num.end());
            return;
        }
        
        int j = i+1;
        while(j<num.size()){
            if(num[j]<=num[i])
                break;
            ++j;
        }
        
        swap(num[i],num[j-1]);
        reverse(num.begin()+i+1, num.end() );
        
    }
    
};