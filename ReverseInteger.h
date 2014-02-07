/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
    	bool neg = false;
        if(x==0)
        	return 0;
        if(x<0){
        	neg = true;
    		x *= -1;
    	}

    	int y = 0;
    	while(x){
    		y *= 10;
    		y += x%10;
    		x /= 10;
    	}

    	return neg?-y:y;
    }
};