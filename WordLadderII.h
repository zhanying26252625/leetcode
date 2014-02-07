/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

//BFS to generate the graph then DFS to find pathes
class Solution {
public:
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> & dict) {
                unordered_map<string, vector<string> > graph;
                vector<vector<string> > res;
                unordered_set<string> curr, prev;
                prev.insert(start);
                while (true) {
                        for (auto word : prev) dict.erase(word);
                        for (auto word : prev) {
                                for (int i = 0; i < (int)word.size(); i++) {
                                        string copy = word;
                                        for (char c = 'a'; c <= 'z'; c++) {
                                                if (copy[i] == c) continue;
                                                copy[i] = c;
                                                if (dict.find(copy) == dict.end()) continue;
                                                graph[copy].push_back(word);
                                                curr.insert(copy);
                                        }
                                }
                        } 

                        if (curr.size() == 0) return res;
                        if (curr.find(end) != curr.end()) break;

                        prev = curr;
                        curr.clear();
                }

                vector<string> path;
                getPath(end, start, graph, path, res);
                return res;
        }

        void getPath(string & start, string & end, unordered_map<string, vector<string> > & graph, vector<string> & path, vector<vector<string> > & res) {
                path.push_back(start);
                if (start == end) {
                        res.push_back(vector<string>(path.rbegin(), path.rend()));
                }
                else {
                        for (auto it : graph[start]) {
                                getPath(it, end, graph, path, res);
                        }
                }
                path.pop_back();
        }
};