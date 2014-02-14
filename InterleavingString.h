/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:

    //reduce exponetial to polynomial
    
    //dp1
    unordered_set<string> bad;
    
    bool isInterleave(string s1, string s2, string s3) {
        static string BAD("#_#");
        if(s1.size()+s2.size()!=s3.size())
            return false;
        
        if(s1=="") return s2==s3;
        if(s2=="") return s1==s3;
        
        if(bad.count(s1+BAD+s2+BAD+s3))
            return false;
            
        if(s1[0]==s3[0] && isInterleave(s1.substr(1),s2,s3.substr(1)) )
            return true;
        
        if(s2[0]==s3[0] && isInterleave(s1,s2.substr(1),s3.substr(1)) )
            return true;
            
        bad.insert(s1+BAD+s2+BAD+s3);
        return false;
        
    }

    //dp2
    bool isInterleave2(string & s1, string & s2, string & s3) {
        int M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        vector<vector<bool> > dp(M + 1, vector<bool>(N + 1, 0));
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = (s2[j - 1] == s3[j - 1]) && dp[i][j - 1];
                else if (j == 0) dp[i][j] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][j];
                else dp[i][j] = ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]) || ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]);
            }
        }
        return dp[M][N];
    }    
};
