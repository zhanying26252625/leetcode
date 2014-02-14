/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:

    string addBinary(string a, string b) {
        
        if(a=="0"){
            return b;
        }
        if(b=="0"){
            return a;
        }
        
        string c(max(a.size(),b.size())+1,'0');
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        a += string(c.size()-a.size(),'0');
        b += string(c.size()-b.size(),'0');
        
        int carry = 0;
        for(int i = 0 ; i < c.size(); ++i){
            
            int ai = a[i]-'0';
            int bi = b[i]-'0';
            
            if( (ai^bi^carry)
                c[i] = '1';
            else
                c[i] = '0';
                
            if(ai&&bi || ai&&carry || bi&&carry)
                carry = 1;
            else
                carry = 0;
        }
        
        if(c[c.size()-1]=='0')
            c = c.substr(0,c.size()-1);

        reverse(c.begin(),c.end());
        
        return c;
    }
    
};