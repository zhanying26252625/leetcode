/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/


class Solution {
public:
    static const string keypad[8];

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        letterCombinationsHelper(digits, 0, "", res);
        return res;
    }

    void letterCombinationsHelper(string& digits, int i, string str, vector<string> & res) {
        if (i == (int)digits.size()) {
            res.push_back(str);
            return;
        }
        int pos = digits[i] - '2';
        for (int j = 0; j < (int)keypad[pos].size(); j++) {
            letterCombinationsHelper(digits, i + 1, str + keypad[pos][j], res);
        }
    }
};

const string Solution::keypad[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
