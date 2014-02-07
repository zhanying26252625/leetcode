/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:

   int sqrt(int x) {
        if(x < 2) return x;
        long long l = 1;
        long long u = 1 + (x / 2);
        while(l + 1 < u) {
            long long m = l + (u - l) / 2;
            long long p = m * m;
            if(p > x)
                u = m;
            else if(p < x)
                l = m;
            else
                return m;
        }
        return (int)l;
    }
    
};

//how about double sqrt(double x)