/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:

    vector<vector<int> > combine(int n, int k) {
        
        vector<vector<int> > vv;
        if(n==0||k==0||k>n)
            return vv;
            
        vector<int> v;
        for(int i = 1; i <= n ; ++i){
            v.push_back(i);
        }
        
        vector<int> cur;
        
        combine2(&vv,cur,0,v,k);
    
        return vv;    
    }
    
	//logic: escape all previous and choosing one
    void combine(vector<vector<int> >* vv, vector<int>& cur, int index, vector<int>& v, int k){
    
        if(cur.size()==k){
            vv->push_back(cur);
            return;
        }

        for(int i = index; i < v.size(); ++i ){
            cur.push_back(v[i]);
            combine(vv,cur,i+1,v,k);
            cur.pop_back();
        }
        
    }
    
	//logic: either choose myself or escape myself
    void combine2(vector<vector<int> >* vv, vector<int>& cur, int index, vector<int>& v, int k){
    
        if(cur.size()==k){
            vv->push_back(cur);
            return;
        }
        
        if(index >= v.size())
            return;

        cur.push_back(v[index]);
        combine(vv,cur,index+1,v,k);
        cur.pop_back();
            
        combine(vv,cur,index+1,v,k);
    }
    
};













