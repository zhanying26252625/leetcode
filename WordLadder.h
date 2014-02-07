/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    
    vector<string > getNeighbors(const string& s,  unordered_set<string> &dict){
        
        vector<string > neighbors;
        
        string start(s);
        
        for(int i = 0; i < start.size(); ++i){

            for(int j = 'a' ; j <= 'z' ; ++j){
                start[i] = j;
                if( dict.count(start) > 0){
                    neighbors.push_back(start);
                    dict.erase(start);
                }
            }
            start = s;
        }
        
        return neighbors;
    }
    
    //BFS
    int ladderLength(string start, string end, unordered_set<string> &dict) {

        queue<pair<string,int> > q;
        q.push(pair<string,int>(start,1));
        dict.erase(start);
        
        while(q.empty()==false){
            
            pair<string,int> pair = q.front();
            q.pop();
            if(pair.first==end){
                return pair.second;
            }
            else{
                
                vector<string > neighbors = getNeighbors( pair.first, dict);
                
                for(int i = 0; i < neighbors.size(); ++i){
                    q.push( std::pair<string,int>(neighbors[i],pair.second+1) );
                }
            }
        }
        
        //not found
        return 0;
    }
    
};