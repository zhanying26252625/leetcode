/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:

    string simplifyPath(string path) {
        
            vector<string> stack;   
            assert(path[0]=='/');  //assume absolute path is given

            int i=0;   
            while( i < path.size())   
            {   
                 while(path[i] =='/' && i< path.size()) i++; //skip the begining '////'  
                 if(i == path.size())   
                      break;   
                 int start = i;   
                 while(path[i]!='/' && i< path.size()) i++; //decide the end boundary  
                 int end = i-1;   
                 string element = path.substr(start, end-start+1);   
                 if(element == "..")   
                 {   
                      if(stack.size() >0)   
                      stack.pop_back();   
                 }   
                 else if(element!=".") { 
                     stack.push_back(element);    
                }
            }   
            
            if(stack.size() ==0) return "/";   
            string simpPath;   
            for(int i =0; i<stack.size(); i++)   
            simpPath += "/" + stack[i];   
            return simpPath; 
    }
    
};