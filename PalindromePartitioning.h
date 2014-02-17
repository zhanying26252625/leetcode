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
    vector<vector<string>> partition(string s) {
        //return partition1(s);
        return partition2(s);
    }
    
    //Top-down DP
    vector<vector<string>> vv;
    vector<vector<string>> partition1(string s) {
        if(s=="")
            return vv;
        vector<string> v;    
        partitionHelper(v,s);
        return vv;
    }
    
    void partitionHelper(vector<string> v, string s){
        if(s==""){
            vv.push_back(v);
            return ;
        }
        
        for(int i = 1; i <= s.size(); ++i){
            string prefix = s.substr(0,i);
            string suffix = s.substr(i);
            if(isPalindrome(prefix)){
                v.push_back(prefix);
                partitionHelper(v,suffix);
                v.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        static unordered_map<string,bool> cache; // cache palindrom substring
        if(s=="")
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
    
    //Bottom-up DP
    vector<vector<string>> partition2(string s) {
        vector<vector<string>> vv;
        if(s=="")
            return vv;
        int N=s.size();
        vector<vector<bool> > dp1(N,vector<bool>(N,false) );//cache isPalindrome
        vector<vector<vector<string> > > dp2(N, vector<vector<string> >());//cache intermediate results
        
        for(int i = 0; i < N; ++i){
            for(int j = i ;j >= 0 ; --j){
                if(s[i]==s[j]&&(i-j<2||dp1[j+1][i-1])){ // if it palindrome
                    dp1[j][i]=true;
                    int len = i-j+1;
                    if(j==0){
                        dp2[i].push_back(vector<string>(1, s.substr(0, len)));
                    }
                    else{
                        for (int k = 0; k < dp2[j-1].size(); ++k ) {
                            vector<string> p = dp2[j-1][k];
                            p.push_back(s.substr(j, len));
                            dp2[i].push_back(p);
                        }
                    }
                }
            }
        }
        
        return dp2[N-1];
    }
    
};



