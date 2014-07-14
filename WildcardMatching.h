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
    http://blog.csdn.net/a83610312/article/details/9750655

    class Solution {
public:

    bool isMatch(const char *s, const char *p) {
        
        return isMatch1(s,p);
    }
    
    //greedy
    bool isMatch1(const char *s, const char *p) {
        assert(s && p);
        const char* star=NULL;
        const char* saveS=NULL;
        while(*s){
            if(*p==*s||*p=='?'){ ++s;++p; }
            else if( *p=='*'){ star=p;saveS=s;++p;}
            else if(star){ p=star;++p;s=saveS;++saveS; }
            else{ return false;}
        }
        while(*p=='*') ++p;
        return *p==0;
    }
    
     //dp, exceed memory limit
     bool isMatch2 (const char *s, const char *p) {
        assert(s && p);
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool> > dp(ls+1,vector<bool>(lp+1,false) );
        dp[0][0]=true;
        for(int i = 1; i <=lp; ++i){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
        }
        
        for(int i = 1; i <= ls; ++i){
            for(int j = 1; j <= lp; ++j){
                if(p[j-1]!='*'){
                    dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
                }
                //current char in pattern is *
                else{
                    dp[i][j]=dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j]  ;
                }
            }
        }
        
        return dp[ls][lp];
     } 
     
     //dp, only use two rows
     bool isMatch3 (const char *s, const char *p) {
        assert(s && p);
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool> > dp(2,vector<bool>(lp+1,false) );
        dp[0][0]=true;
        for(int i = 1; i <=lp; ++i){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
        }
        
        for(int i = 1; i <= ls; ++i){
            int curRow=i%2;  
            int preRow=(i+1)%2;
            for(int j = 1; j <= lp; ++j){
                if(p[j-1]!='*'){
                    dp[curRow][j]=dp[preRow][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='?');
                }
                //current char in pattern is *
                else{
                    dp[curRow][j]=dp[curRow][j-1] || dp[preRow][j-1] || dp[preRow][j]  ;
                }
            }
        }
        
        return dp[ls%2][lp];
     } 
     
};
*/



};