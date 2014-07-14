/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:

    
    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        if(x>=0&&x<=9)
            return true;
            
        int numDigits = (int)floor( log10(x) );
        
        while(x!=0){
            
            int most = x / pow(10,numDigits) ;
            int least = x % 10;
            if(most!=least)
                return false;
            x -= most * pow(10,numDigits);
            x /= 10;
            
            numDigits -= 2;
        }
        
        return true;
    }
    
    
};