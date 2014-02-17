/*
Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:

   int divide(int dividend, int divisor) {
       
        assert(divisor != 0);
        
        bool flag = dividend > 0 && divisor < 0 || 
                    dividend < 0 && divisor > 0;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;
        while (dividendll >= divisorll)
        {
            long long div = divisorll;
            int quot = 1;
            while ((div << 1) <= dividendll) {
                div <<= 1;
                quot <<= 1;
            }
            dividendll -= div;
            res += quot;
        }
        
        return flag ? -res : res;
    }
	
	int divide1(int dividend, int divisor) {
        
        int neg = 1;
        if( (dividend>0) ^ (divisor>0) )
            neg = -1;
        
        long long dividend1 = abs((long long)dividend);
        long long divisor1 = abs((long long)divisor);
        
        int ret = 0;
        
        while(dividend1>=divisor1){
            
            int j = 0;
            while(dividend1 >= divisor1<<(j+1))
                ++j;
            
            dividend1 -= divisor1<<j;
            ret += 1<<j;
        }
        
        return ret*neg;
    }
};