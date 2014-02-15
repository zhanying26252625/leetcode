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
    
	//DP top-down O(N^2)
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
	
	//DP bottom-up O(N^2)
	/*
	bool wordBreak(string s, unordered_set<string> &dict) {
        if(s=="")
            return false;
            
        vector<bool> can(s.size()+1,false);
        can[0]=true;
        for(int i = 1 ; i <= s.size(); ++i){
            for(int j = i; j>=1; --j){
                if(can[j-1]&&dict.count(s.substr(j-1,i-j+1))>0) { can[i]=true;break; }
            }
        }
        return can[s.size()];
    }
	*/
};