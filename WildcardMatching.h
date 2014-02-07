/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
/*
Analysis:

For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;
*/
    //very clever
    bool isMatch(const char *s, const char *p) {

        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
    
//Timeout, so many recursion even if optimized
/*
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0') {
            if (*p == '\0') return true;
            if (*p == '*') return isMatch(s,p+1);
            return false;
        }
        if (*p == '\0') return false;
        if (*p == '?' || *p == *s) return isMatch(s+1, p+1);
        if (*p=='*'){ 
            //advance * as much as possible
            while(*p=='*')
                ++p;
            if(*p=='\0')
                return true;
            --p;
            return isMatch(s+1,p) || isMatch(s, p+1);
        }
        
        return false;
    }
*/

};