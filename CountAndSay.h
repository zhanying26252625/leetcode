/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:

    string countAndSay(int n) {
        
        string s = "1";
        
        for(int i = 1; i < n; ++i){
            
            stringstream ss;
            
            int b = 0;
            int e = 1;
            
            while(e!=s.size()){
                if(s[e]!=s[b]){
                    ss << e-b << s[b];
                    b = e;
                }
                ++e;
            }
            ss << e-b << s[b];
            
            s = ss.str();
        }
        
        return s;
    }
};