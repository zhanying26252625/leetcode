/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    unordered_map<int,int> cache;
    int climbStairs(int n) {
        if(n==0||n==1)
            return 1;
        
        if(cache.count(n))
            return cache[n];
        
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
        return cache[n];
    }
};

/*
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1;
        int b = 2;
        int c;
        for (int i = 2; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
*/