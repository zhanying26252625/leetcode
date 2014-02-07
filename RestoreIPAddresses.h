/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:

    vector<string> v;
    
    vector<string> restoreIpAddresses(string s) {
        
        if(s.size()< 4 || s.size() > 12)
            return v;
            
        string curStr;
        restoreIpAddresses(s,curStr,0);
        
        return v;
    }
    
    bool isValid(string num){
        
        if(num=="")
            return false;
            
        int n = atoi(num.c_str());
        if(num.size()==1){
            return n>=0&&n<=9;
        }
        else if(num.size()==2){
            return n>=10&&n<=99;
        }
        else if(num.size()==3){
            return n>=100&&n<=255;
        }
        
        return false;
        
    }
    
    void restoreIpAddresses(string s, string curStr, int index){
        
        if(index==4 && s=="" ){
            v.push_back(curStr.substr(1));
            return;
        }
        
        if(s=="")
            return;
        
        for(int i = 1; i <= 3 && i <= s.size(); ++i){
            string num = s.substr(0,i);
            if( isValid(num)){
                restoreIpAddresses(s.substr(i),curStr+"."+num,index+1);
            }
        }
            
    }
};


