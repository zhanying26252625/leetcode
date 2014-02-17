/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if(s.size()<4||s.size()>12)
            return v;
        vector<string> cur;   
        restoreIpAddresses(v,s,cur);
        return v;
    }
    
    void restoreIpAddresses(vector<string>& v, string s, vector<string>& cur){
        
        if(cur.size()==4&&s==""){
            stringstream ss;
            for(int i = 0 ; i < cur.size(); ++i)
                ss<<'.'<<cur[i];
            v.push_back(ss.str().substr(1));
            return;
        }
        
        if(cur.size()==4) return;
        
        int len = std::min(3,(int)s.size());
        for(int i = 1; i <= len; ++i){
            string prefix = s.substr(0,i);
            if(isValid(prefix)){
                cur.push_back(prefix);
                restoreIpAddresses(v,s.substr(i),cur);
                cur.pop_back();
            }
        }
    }
    
    bool isValid(string& s){
        if(s=="") return false;
        if(s.size()==1) return s[0]>='0'&&s[0]<='9';
        if(s.size()==2) return atoi(s.c_str())>=10;
        if(s.size()==3) return atoi(s.c_str())>=100&&atoi(s.c_str())<=255;
        return false;
    }
    
};


