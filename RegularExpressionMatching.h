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

/*
http://blog.csdn.net/lifajun90/article/details/10582733
http://blog.csdn.net/a83610312/article/details/9750655


*/
 
 class Solution {
public:

    bool isMatch (const char *s, const char *p) {
    
        return isMatch2(s,p);
    }
    
    //recursion
    bool isMatch1 (const char *s, const char *p) {
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
    }
    
    //dp
     bool isMatch2 (const char *s, const char *p) {
        assert(s && p);
        int ls = strlen(s);
        int lp = strlen(p);
        vector<vector<bool> > dp(ls+1,vector<bool>(lp+1,false) );
        dp[0][0]=true;
        for(int i = 1; i <=lp; ++i){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-2];
        }
        
        for(int i = 1; i <= ls; ++i){
            for(int j = 1; j <= lp; ++j){
                if(p[j-1]!='*'){
                    dp[i][j]=dp[i-1][j-1]&&(s[i-1]==p[j-1]||p[j-1]=='.');
                }
                //current char in pattern is *
                else{
                    dp[i][j]=dp[i][j-2] || dp[i][j-1] || (dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.')) ;
                }
            }
        }
        
        return dp[ls][lp];
        
     } 
    
};