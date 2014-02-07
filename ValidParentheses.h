/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:

    unordered_map<char,char> hash;
    
    bool isValid(string s) {
        hash['(']=')';
        hash['{']='}';
        hash['[']=']';
        
        if(s=="")
            return true;
            
        if(s.size()%2!=0)
            return false;
            
        stack<char> stack;
        int i = 0;
        
        while(i<s.size()){
            char c = s[i];
            if( c=='(' || c=='{' || c=='[' ){
                stack.push(c);
            }else if(c==')' || c=='}' || c==']'){
                if(stack.empty()==true)
                    return false;
                char cc = stack.top();
                stack.pop();
                if(hash[cc] != c)
                    return false;
            }
            else{
                return false;
            }
            ++i;
        }
        
        if(stack.empty())
            return true;
        return false;
    }
};