/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

//O(N^3) with cache, otherwise O(2^N)
class Solution {
public:

    vector<vector<string> > retVV;
    
    bool isPalindrome(string s){
        
        static unordered_map<string,bool> cache;
        
        if(s.size()==0)
            return true;
            
        if(cache.count(s)>0)
            return cache[s];
            
        for(int i = 0 , j = s.size()-1; i<=j; ++i,--j ){
            if(s[i]!=s[j]){
                cache[s]=false;
                return false;
            }
        }
        
        cache[s]=true;
        return true;
    }

    void partitionHelper(string s, vector<string>& v){
        
        if(s==""){
            retVV.push_back(v);
            return;
        }
        
        for(int i = 1 ; i <= s.size() ; ++i){
            string prefix = s.substr(0,i);
            string suffix("");
            if(i!=s.size())
                suffix = s.substr(i);
            if( isPalindrome(prefix) ){
                v.push_back(prefix);
                partitionHelper(suffix,v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string> > partition(string s){
        vector<string> v;
        partitionHelper(s,v);
        return retVV;
    }
    
};

/*
class Solution {
public:
    vector<vector<string> > partition(string s) {
        return partition2(s);
    }

    vector<vector<string> > partition2(string & s) {
        int N = s.size();
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        vector<vector<vector<string> > > dp2(N, vector<vector<string> >());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || dp1[j + 1][i - 1])) {
                    dp1[j][i] = true;
                    if (j == 0) {
                        dp2[i].push_back(vector<string>(1, s.substr(j, i - j + 1)));
                    }
                    else {
                        for (auto p : dp2[j - 1]) {
                            p.push_back(s.substr(j, i - j + 1));
                            dp2[i].push_back(p);
                        }
                    }
                }
            }
        }
        return dp2[N - 1];
    }
};

*/