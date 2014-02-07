/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:

    vector<int> findSubstring(string S, vector<string> &L) {
        
        vector<int> v;
        
        if(S==""||L.size()==0||L[0].size()==0)
            return v;
        
        int len = L[0].size();
        
        if(S.size()<len*L.size())
            return v;
        
        unordered_map<string,int> needs;
        for(int i = 0 ; i < L.size(); ++i){
            needs[L[i]]++;
        }
        
        for(int i = 0; i <= S.size()-len*L.size(); ++i){
            unordered_map<string,int> founds;
            int j = 0;
            for(; j < L.size(); ++j){
                string str = S.substr(i+j*len,len);
                if(needs.count(str)==0)
                    break;
                founds[str]++;
                if(founds[str]>needs[str])
                    break;
            }
            
            if(j==L.size()){
                    v.push_back(i);
            }
        }    
        
        return v;
    }
    
};