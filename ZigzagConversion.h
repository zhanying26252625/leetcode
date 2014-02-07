/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
*/
class Solution {
public:
    string convert(string s, int nRows)
    {
        if (nRows < 2) return s;
        int N = s.size();
        int L = 2 * (nRows - 1); // provide gap
        string res;
        res.clear();
        
        for (int i = 0; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        for (int i = 1; i < nRows - 1; i++)
        {
            for (int j = i; j < N; j += L)
            {
                int l = L-2*i; //small gap
                res.push_back(s[j]);
                int k = j+l;
                if (k < N) res.push_back(s[k]);
            }
        }
        for (int i = nRows - 1; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        
        return res;
    }
};