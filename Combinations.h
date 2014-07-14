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

    int nextSameBits(int bits){
        int firstBit = bits&(~(bits-1));
        int big = firstBit + bits;
        int remains = ((big^bits)>>2) / firstBit;
        return big + remains;
    }

    //iteratively by using bits manipulation
    void combine3(vector<vector<int> >* vv , vector<int>& cur,int k){
        int begin = 0;
        int end = 0;
        for(int i = 0 ; i < k ; ++i ) begin |= 1<<i; 
        end = begin << (cur.size()-k) ;
        
        while(begin <= end){
            int bits = begin;
 
            vector<int> v;
            while(bits){
                int i = 0; 
                while( 1<<i != (bits&(~(bits-1))) ) ++i;            
                bits = bits & (bits-1);
                v.push_back(cur[i]);
            }
            vv->push_back(v);
            
            begin = nextSameBits(begin);
        }
 
    }
    
};













