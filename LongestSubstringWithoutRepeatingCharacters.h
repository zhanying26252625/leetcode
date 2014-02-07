/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        //char,index 
        unordered_map<char,int> cache;
        
        int max = 0;
        int len = 0;
        for(int i = 0; i < s.size(); ++i){
            if(cache.count(s[i])==0){
                cache[s[i]]=i;
                ++len;
                max = std::max(max,len);
            }
            else{
                int preIndex = cache[s[i]];
                
                for(int j = preIndex; j >= i - len ; --j){
                    cache.erase(s[j]);
                }
                cache[s[i]]=i;
                len = cache.size();
                
            }
        }
        
        return max;
    }
    
};