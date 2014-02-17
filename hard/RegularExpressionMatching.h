/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:

   bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if (*p == '\0') return *s == '\0';

        if (*(p+1) != '*') {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    };
    
    bool isMatch1(const char *s, const char *p) {
        
        string str(s);
        string pattern(p);
        
        isMatch1(str,pattern);
    }

    bool isMatch1(string s, string p){
        
            if( p=="" )
                return s=="";
        
            if(p[1]!='*'){
                if(s[0]==p[0]|| (p[0]=='.' && s!="") )
                    return isMatch1(s.substr(1),p.substr(1));
                return false;
            }
            else{
                
                if( isMatch1(s,p.substr(2)) )
                    return true;
                    
                for(int i = 0; i<s.size(); ++i){
                    if(s[i]==p[0]|| p[0]=='.'){
                        if(isMatch1(s.substr(i+1),p.substr(2)))
                            return true;
                    }
                    else{
                        break;
                    }
                }
                
                return false;
            }
        
    }
    
};