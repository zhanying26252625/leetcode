/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:

    bool isNumber(const char* s) {
        // trim leading/trailing spaces
        while (*s != '\0' && isspace(*s)) s++;
        if (*s == '\0') return false;
        const char *e = s + strlen(s) - 1;
        while (e > s && isspace(*e)) e--;
        // skip leading +/-
        if (*s == '+' || *s == '-') s++;

        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool exp = false; // is a 'e'
        while (s != e + 1) {
            if (*s >= '0' && *s <= '9') {
                num = true;
            }
            else if (*s == '.') {
                if(exp || dot) return false;
                dot = true;
            }
            else if (*s == 'e') {
                if(exp || num == false) return false;
                exp = true;
                num = false;
            }
            else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e') return false;
            }
            else {
                return false;
            }
            s++;
        }
        return num;
    }
	
	
	   //state machine
	   bool isNumber1(const char *s) {
        if(*s==0) return false;
        enum Action {INVALID=0, SPACE=1, SIGN=2, DIGIT=3, DOT=4, EXPONENT=5};
        const int N = 6;
        //[state][action]
        int transTable[][N] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        int state = 0;
        while(*s){
            Action act = INVALID;
            if (*s == ' ')
                act = SPACE;
            else if (*s == '+' || *s == '-')
                act = SIGN;
            else if (isdigit(*s))
                act = DIGIT;
            else if (*s == '.')
                act = DOT;
            else if (*s == 'e')
                act = EXPONENT;
            state = transTable[state][act];
            if (state == 0) return false;
            s++;
        }
        
        bool validStates[]={0,0,0,1,0,0,1,1,1};
        return validStates[state];
    }
	
};