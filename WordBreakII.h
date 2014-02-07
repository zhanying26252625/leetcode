/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
    
public:

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<vector<int> > dp(N+1, vector<int>()); // dp[i][j] means ends at i, previous valid end at j
        dp[0].push_back(0);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= i; j++)
                if (dp[i-j].size() && (dict.find(s.substr(i-j, j)) != dict.end()))
                    dp[i].push_back(i-j);
        return wordBreakHelper(s, dp, N);
    }

    vector<string> wordBreakHelper(string & str, vector<vector<int> > & dp, int i) {
        vector<string> res;
        for (int j = 0; j < (int)dp[i].size(); j++) {
            if (dp[i][j] == 0) {
                res.push_back(str.substr(0, i));
            }
            else {
                string tmp = str.substr(dp[i][j], i-dp[i][j]);
                vector<string> sub = wordBreakHelper(str, dp, dp[i][j]);
                for (int k = 0; k < (int)sub.size(); k++) {
                    res.push_back(sub[k]+" "+tmp);
                }
            }
        }

        return res;
    }
    
};