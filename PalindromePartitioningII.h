/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:

int minCut(string s){

    int n = s.size();  
    
    vector<vector<bool> > dp(n, vector<bool>(n,false) );  
    
    for(int i=0;i<n;i++)  
        dp[i][i]=true;  
        
    //number of palindrome strings from o to i
    vector<int> f(n,0);  
    for(int i=0;i<n;i++)  
        f[i]=i+1;  
        
    for(int j=1;j<n;j++)  
    {  
        for(int i=j;i>=0;i--)  
        {  
            if(s[i]==s[j]&&(j-i<2||dp[i+1][j-1]))  
            {  
                dp[i][j]=true;  
                if(i==0)  
                    f[j]=min(f[j],1);  
                else  
                    f[j]=min(f[j],f[i-1]+1);  
            }  
        }  
    }  
    return f[n-1]-1; 
    
}
};