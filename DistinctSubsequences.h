/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:

    int numDistinct(string S, string T) {
        
        vector<vector<int> > dp(S.size()+1,vector<int>(T.size()+1,0) );
       
        for(int i =0 ;i < S.size(); ++i){
            dp[i][0]=1;
        }
        
        for(int i = 1 ; i <= S.size() ; ++i ){
            for(int j = 1; j <= T.size(); ++j){
                int num = dp[i-1][j];
                if(S[i-1]==T[j-1]){
                    num += dp[i-1][j-1];
                }
                dp[i][j] = num;
            }
        }
        
        return dp[S.size()][T.size()];
        
    }
    
};