/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:

    int minDistance(string word1, string word2) {
        if(word1=="")
            return word2.size();
        if(word2=="")
            return word1.size();
        
        int row = word1.size()+1;
        int col = word2.size()+1;
        vector<vector<int> > dist(row,vector<int>(col,0));
        for(int i =0 ; i < row; ++i){
            dist[i][0] = i;
        }
        for(int i =0 ; i < col; ++i){
            dist[0][i] = i;
        }
        
        for(int i = 1 ; i < row; ++i){
            for(int j = 1 ; j < col; ++j){
                    int d = (word1[i-1]==word2[j-1])?0:1;
                    dist[i][j] = min(dist[i-1][j-1]+d ,min(dist[i][j-1]+1, dist[i-1][j]+1));
            }
            
        }
        
        return dist[word1.size()][word2.size()];
    }
};