/*
Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/


//EPI 12.13 pretty printing, similar but different and more difficult

class Solution {
public:

    string formatLine(const vector<string>& words,int L){
        
        string line(words[0]);
        if(words.size()==1){//only one word
            line += string(L-line.size(),' ');
            return line;
        }
            
        //distribute spaces    
        int chars = 0;
        for(int i = 0; i < words.size(); ++i){
            chars += words[i].size();
        }
        int spaces = L-chars;
        int avg = spaces/(words.size()-1); //average extra spaces
        int head = spaces - (words.size()-1)*avg; //more heading spaces on left
        
        for(int i = 1; i < words.size(); ++i){
            if(head-->0) line += " ";
            line += string(avg,' ') + words[i];
        }
        
        return line;
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        
        vector<string> v; //return set
        if(words.size()==0)
            return v;
 
        vector<string> curLine(1,words[0]);
        int curLen = words[0].size();
        
        for(int i = 1; i < words.size(); ++i){
            string& word = words[i];
            if(curLen + 1 + word.size()<=L){//fits into current line;
                curLine.push_back(word);
                curLen = curLen + 1 + word.size();
            }
            else{ //new line
                v.push_back(formatLine(curLine,L));
                curLine.clear();
                curLine.push_back(word);
                curLen = word.size();
            }
        }
        
        string line(curLine[0]); //last line, no extra space
        for(int i = 1 ; i < curLine.size(); ++i)
            line += " " + curLine[i];
        line += string(L-line.size(),' ');
        v.push_back(line);
        
        return v;
    }
};