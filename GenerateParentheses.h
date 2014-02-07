/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:

    void generateParenthesis(int pre, int post , string s, vector<string>& v){
        
        if(pre>post||pre<0||post<0){
            return;
        }
        
        if(pre==0&&post==0){
            v.push_back(s);
            return;
        }

        generateParenthesis(pre-1,post,s+"(",v);
        generateParenthesis(pre,post-1,s+")",v);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if(n==0)
            return v;
            
        string s;
        generateParenthesis(n,n,s,v);
        return v;
    }
    
};