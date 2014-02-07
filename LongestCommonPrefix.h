/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:

    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)
            return "";
            
        for(int i = 0 ; i < strs[0].size(); ++i ){
            char c =  strs[0][i];
            bool found = true;
            for(int j = 1; j < strs.size(); ++j){
                if( c != strs[j][i] ){
                    found = false;
                    break;
                }
            }
            if(!found){
                return strs[0].substr(0,i);
            }
        }
        
        return strs[0];
    }
    
};