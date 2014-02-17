/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:

    int minCut(string s) {
        if(s.size()<2)
            return 0;

        int N = s.size();
        vector<vector<bool> > dp(N,vector<bool>(N,false) ); //cache palindrome substrs
        vector<int> minCuts(N,INT_MAX); // cache intermediate min cuts

        for(int i = 0; i < N; ++i){
            for(int j = i ;j >= 0 ; --j){
                if(s[j]==s[i]&&(i-j<2||dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(j==0){
                        minCuts[i] = 0;
                    }
                    else{
                        minCuts[i] = std::min(minCuts[i],minCuts[j-1]+1);
                    }
                }
            }
        }
        return minCuts[N-1];
    }
};
