/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:

    struct MyComp{
      bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
          return p1.first < p2.first;
      }  
    };
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        assert(numbers.size()>=2);
        
        vector<int> v(2,0);
        vector<pair<int,int> > pairs;
        for(int i = 0; i<numbers.size();++i){
            pairs.push_back(pair<int,int>(numbers[i],i+1));
        }
        
        sort(pairs.begin(),pairs.end(),MyComp());
        
        for(int i = 0, j = pairs.size()-1; i<j ; ){
            int vi = pairs[i].first;
            int vj = pairs[j].first;
            if( vi + vj == target){
                v[0]=pairs[i].second;
                v[1]=pairs[j].second;
                break;
            }
            else if( vi + vj > target){
                --j;
            }
            else{
                ++i;
            }
        }
        
        if(v[0]>v[1])
            swap(v[0],v[1]);
            
        return v;
                
    }
    
};