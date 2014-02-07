/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

class Solution {
public:
    char * strStr(char * haystack, char * needle) {
        if (!haystack || !needle) return haystack;
        int n = strlen(haystack);
        int m = strlen(needle);
        if (n < m) return NULL;
        if (m == 0) return haystack;
        return strStr3(haystack, n, needle, m);
    }

    // brute force, takes O(n*m) time
    char *strStr1(char *haystack, int n, char *needle, int m) {
        int i = 0;
        while (i < n-m+1) {
            int j = 0;
            while (j < m && haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == m) return haystack+(i-j);
            i = i-j+1;
        }
        return NULL;
    }
    
    /*
    // Rabin-Karp (RK), takes O(n+m) times, but O(n*m) worst case
    char * strStr2(char * haystack, int n, char * needle, int m) {
        int hn = 0;
        for (int i = 0; i < m; i++) hn = mod(hn*B+needle[i], M);

        int hh = 0;
        for (int i = 0; i < m; i++) hh = mod(hh*B+haystack[i], M);

        if (hh == hn) return haystack;

        int E = 1;
        for (int i = 1; i < m; i++) E = mod(E*B, M);

        for (int i = m; i < n; i++) {
            hh = mod(hh-mod(haystack[i-m]*E, M), M);
            hh = mod(hh*B+haystack[i], M);

            if (hh == hn) {
                int j = 0;
                while (j < m && haystack[i+j] == needle[j]) j++;
                return haystack+i-m+1;
            }
        }
        return NULL;
    }

    int mod(int a, int b) {
        return (a%b+b)%b;
    }
    */
    
    // Knuth-Morris-Pratt Algorithm (KMP), takes O(n+m)
    char * strStr3(char * haystack, int n, char * needle, int m) {
        vector<int> fs = build(needle, m);
        int i = 0, j = 0;
        int step = 10000;
        while (j < n) {
            if (j == n) break;
            if (haystack[j] == needle[i]) {
                i++;
                j++;
                if (i == m) return haystack+j-m;
            }
            else if (i > 0) i = fs[i];
            else j++;
            step--;
            if (step == 0) break;
        }
        return NULL;
    }

    vector<int> build(char * needle, int m) {
        vector<int> fs(m+1, 0);
        for (int i = 2; i <= m; i++) {
            int j = fs[i-1];
            while (true) {
                if (needle[j] == needle[i-1]) {
                    fs[i] = j+1;
                    break;
                }

                if (j == 0) {
                    fs[i] = 0;
                    break;
                }

                j = fs[j];
            }
        }

        return fs;
    }
};