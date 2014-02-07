/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative
*/

class Solution {
public:

    int ctoi(char c){
        return c-'0';
    }

    char itoc(int i){
        return i +'0';
    }
    
    string multiply(string num1, string num2) {
        
        if(num1=="0"||num2=="0")
            return "0";
        
        string ret(num1.size()+num2.size(),'0');
        
        for(int i = num1.size()-1; i>=0; --i){
            int a = ctoi(num1[i]);
            int j = num2.size()-1;
            int carry = 0;
            for(; j>=0; --j){
                int b = ctoi(num2[j]);
                int sum = a * b + carry + ctoi(ret[i+j+1]);
                ret[i+j+1] = itoc(sum % 10);
                carry = sum / 10;
            }
            if(carry)
                ret[i+j+1] = itoc(carry);
        }
        
        int k = 0;
        while(ret[k]=='0')
            ++k;
            
        ret=ret.substr(k);
        
        return ret;
    }
    
};