/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    //O(N)
    int longestConsecutive(vector<int> &num) {
	
        if(num.size()<=1)
            return num.size();
        
        unordered_set<int> hash;
        for(int i = 0 ; i < num.size(); ++i){
            hash.insert(num[i]);
        }
        
        int max = 0;
        
        while(!hash.empty()){
            int m = *(hash.begin());
            hash.erase(m);
            int l = m-1;
            int h = m+1;
            while(hash.count(l)>0){
                hash.erase(l);
                --l;
            }
            while(hash.count(h)>0){
                hash.erase(h);
                ++h;
            }
            
            max = std::max(max,h-l-1);
        }
        
        return max;
        
        
    }
};