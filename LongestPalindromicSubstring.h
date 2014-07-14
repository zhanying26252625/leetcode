/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:

    string longestPalindrome(string s) {
        return longestPalindrome2(s);
    }

    // take O(n^2) time, O(n^2) space
    string longestPalindrome1(string s) {
        if(s==""||s.size()==1)
            return s;
        
        int maxLen=1;
        int begin = 0;
        
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(),false) );
        
        for(int i = 0; i < s.size(); ++i){
            dp[i][i]=true;
            if(i<s.size()-1 && s[i]==s[i+1])
                dp[i][i+1]=true;
        }
        
        for(int len = 3; len <= s.size(); ++len){
            for(int i = 0; i + len <= s.size(); ++i){
                int j = i + len - 1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    begin=i;
                    maxLen=len;
                }
            }
        }
        
        return s.substr(begin,maxLen);
        
    }
    
    // take O(n^2) time, O(1) space
    string longestPalindrome2(string s) {
        int n = s.size();
        if (n == 0) return "";
        int maxi = 0;
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int start = i - j;
                int end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end])
                    start--, end++;
                start++, end--;
                int len = end - start + 1;
                if (len > maxl) maxi = start, maxl = len;
            }
        }
        return s.substr(maxi, maxl);
    }
    
    
    //O(N) (Manacher's Algorithm)
      string longestPalindrome_4(string s) {
        int N = s.size();
        int dp[2 * N + 1];
        int id = 0, mx = 0;
        for (int i = 0; i < 2 * N + 1; ++i)
        {
            int j = 2 * id - i;
            dp[i] = mx > i ? min(dp[j], mx - i) : 1;
            int left = i - dp[i], right = i + dp[i];
            for (; left >= 0 && right <= 2 * N; left--, right++)
            {
                if (left % 2 == 0 || s[left/2] == s[right/2]) // padding or char
                    dp[i]++;
                else
                    break;
            }
            if (i + dp[i] > mx)
            {
                id = i;
                mx = id + dp[id];
            }
        }

        int res = 0;
        for (int i = 1; i < 2 * N + 1; ++i)
            if (dp[i] > dp[res])
                res = i;

        return s.substr(res / 2 - (dp[res] - 1) / 2, dp[res] - 1);
    }

    /*
    //manacher's O(N)  my implementation
    string longestPalindrome2(string s) {
        //pad the origin string
        stringstream ss;
        ss<<"^#";
        for(int i =0 ; i<s.size(); ++i)
            ss<<s[i]<<"#";
        ss<<"$";
        string text = ss.str();

        //iteratively find longest substring
        vector<int> lens(text.size(),1);
        int c = 1; //center
        int r = 1; //right-side
        for(int i = 2 ; i < text.size(); ++i){
            int j = 2*c-i;
            int l = min(lens[j],max(0,r-i));
            while(i-l>=0&&i+l<text.size()&&text[i-l]==text[i+l]) ++l;
            lens[i] = l;

            if(i+l>=c){
                c = i;
                r = i + l - 1;
            }
        }

        //find max len
        int radius = 0;
        int center = 0;
        for(int i = 0 ; i < lens.size(); ++i){
            if(lens[i] > radius){
                center = i;
                radius = lens[i];
            }
        }
        
        //trim 
        string subs = text.substr(center-radius+1,radius*2-1);
        //cout << subs << endl;
        stringstream ss2;
        for(int i =0 ; i<subs.size(); ++i){
            if(subs[i]!='#'&&subs[i]!='^'&&subs[i]!='$') ss2<<subs[i];  
        }
        string retStr = ss2.str();
        return retStr;
    }

    */
};
