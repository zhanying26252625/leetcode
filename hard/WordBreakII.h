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

class Solution {
public:

    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        if(s==""||dict.size()==0)
            return vector<string>();
        
        // dp[i][j] means when string is at size of i , we have a valid word of length j before it
        vector<vector<int> > dp(s.size()+1,vector<int>());
        
        dp[0].push_back(0); //no valid word before it
        
        for(int i = 1; i <= s.size(); ++i){ //cur size
            for(int j = i; j >= 1 ; --j){ //pre len
                if( dict.count(s.substr(i-j,j))>0 && dp[i-j].size()>0 ){
                    dp[i].push_back(j); // record word len
                }
            }
        }
        
        return buildVec(s,s.size(),dp);
    }
    
    vector<string> buildVec(const string& str, int len, const vector<vector<int> >& dp){
        
        vector<string> v;
        
        for(int i = 0; i < dp[len].size(); ++i){
            int wordLen = dp[len][i];
            if(wordLen==len){
                v.push_back(str);
            }
            else{
                vector<string> pres = buildVec(str.substr(0,len-wordLen),len-wordLen,dp);
                for(int j = 0 ; j < pres.size(); ++j){
                    v.push_back(pres[j]+" " + str.substr(len-wordLen) );
                }
            }
        }
        
        return v;
    }
    
};


/*
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
 */   
};