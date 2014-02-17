/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses2(s);
    }

    int longestValidParentheses1(string & s) {
        int N = s.size(), res = 0, last = -1;
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
                continue;
            }

            if (stk.empty()) {
                last = i; //remember where the latest valid position starts
            }
            else {
                stk.pop();
                res = max(res, stk.empty() ? (i - last) : (i - stk.top()));
            }
        }
        return res;
    }

    int longestValidParentheses2(string & s) {
        int N = s.size();
        return max(longestValidParenthesesHelper(s, '(', 0, N, 1), //(((((((((((((((()
            longestValidParenthesesHelper(s, ')', N - 1, -1, -1)); //())))))))))))))))
    }

    int longestValidParenthesesHelper(string & s, char c, int start, int end, int step) {
        int res = 0, counter_c = 0, pair = 0; // counts of c, and valid pairs
        for (int i = start; i != end; i += step) {
            if (s[i] == c) counter_c++ ;
            else counter_c--, pair++;
            if (counter_c == 0) res = max(res, pair*2);
            else if (counter_c < 0) counter_c = 0, pair = 0;
        }
        return res;
    }
};