/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:

    unordered_set<string> bad;
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s=="")
            return true;
        if(dict.count(s)>0)
            return true;
        if(bad.count(s)>0)
            return false;
        
        for(int end = 1; end<=s.size();++end){
            string prefix = s.substr(0,end);
            string postfix = s.substr(end);
            if(dict.count(prefix)>0 && wordBreak(postfix,dict)){
                return true;
            }
        }
        
        bad.insert(s);
        return false;
    }
};