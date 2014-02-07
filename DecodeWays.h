/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:

	bool isValid(string s){
		if(s.size()>=1&&s.size()<=2){
			int num = 0;
			for(int i = 0; i < s.size(); ++i){
				num *= 10;
				num += (s[i]-'0');
			}
			return (num<=26 && num>=10);
		}
		return false;
	}

    int numDecodings(string s) {
    	if(s==""||s[0]=='0')
    		return 0;

    	//invalid digits
    	for(int i = 0 ; i < s.size(); ++i){
    		if(! (s[i]>='0'&&s[i]<='9') ){
    			return 0;
    		}
    	}

        vector<int> ways(s.size()+1,0);
        ways[0]=1;
        ways[1]=1;

        for(int i = 2; i <= s.size(); ++i){

        	if(s[i-1]!='0')
        		ways[i] += ways[i-1];

        	if(isValid(s.substr(i-2,2)))
        		ways[i] += ways[i-2];
        	
        }

        return ways[s.size()];
    }
    
};