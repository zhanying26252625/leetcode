/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:

	void subsets(vector<int> &S, int index, vector<int>& v, vector<vector<int> >& vv) {

		vv.push_back(v);

		if(index<S.size()){
			for(int i = index; i < S.size(); ++i){
				v.push_back(S[i]);
				subsets(S,i+1,v,vv);
				v.pop_back();
			}
		}
	}

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > vv;
        vector<int> v;
        sort(S.begin(),S.end());
        subsets(S,0,v,vv);
        return vv;
    }

/*
void subsets(vector<int> &S, int index, vector<int>& v, vector<vector<int> >& vv) {

        if(index==S.size()) 
        {
            vv.push_back(v);
            return;
        }

    v.push_back(S[index]);
    subsets(S,index+1,v,vv);
    v.pop_back();
      
    subsets(S,index+1,v,vv);

  }

*/
};