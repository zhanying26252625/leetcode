/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:

    int evalRPN(vector<string> &tokens) {
        
        stack<int> s;
        
        for(int i = 0; i < tokens.size(); ++i){
            
            if(tokens[i]=="+"||
               tokens[i]=="-"||
               tokens[i]=="*"||
               tokens[i]=="/"){
                   int second = s.top();
                   s.pop();
                   int first = s.top();
                   s.pop();
                   if(tokens[i]=="+"){
                       s.push(first+second);
                   }
                   else if(tokens[i]=="-"){
                       s.push(first-second);
                   }
                   else if(tokens[i]=="*"){
                       s.push(first*second);
                   }
                   else{
                       s.push(first/second);
                   }
            }
            else{
                s.push(atoi(tokens[i].c_str()));
            }
        }
        
        return s.top();
    }
    
};