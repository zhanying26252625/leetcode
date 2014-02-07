/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:

    bool isAm(char x){
        if( x>='a'&& x<='z' || x>='A'&&x<='Z' || x>='0'&&x<='9')
            return true;
        return false;
    }
    
    bool isA(char x){
        if( x>='a'&& x<='z' || x>='A'&&x<='Z')
            return true;
        return false;
    }
    
    bool isEqual(char a, char b){
        
        if(a==b)
            return true;
            
        if(  isA(a) && isA(b) && abs(a-b) == abs('a'-'A') )
            return true;

        return false;
    }

    bool isPalindrome(string s) {
        
        if(s=="")
            return true;
        if(s.size()==1)
            return true;
        if(s.size()==2&&isEqual(s[0],s[1]))
            return true;
        
        for(int i = 0, j = s.size()-1; i < j; ){
            while( i<j && ! isAm(s[i]) )
                ++i;
            
            while( i<j && ! isAm(s[j]) )
                --j;
                
            if(i<j){
                if( !isEqual(s[i],s[j]) )
                    return false;
                
                ++i;
                --j;
            }
            else{
                break;
            }
        }    
            
        return true;
    }
};