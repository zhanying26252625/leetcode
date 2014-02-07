/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:

    int findkthSmall(vector<bool>& used, int k){
        int count = 0;
        for(int i = 0; i < used.size(); ++i){
            if(!used[i])
                ++count;
            if(count == k){
                used[i]=true;
                return i+1;
            }
        }
        return 0;
    }
    
    //use math method, very clever
    string getPermutation(int n, int k) {
        
        vector<int> v(n,1);
        for(int i = 2; i <= n ; ++i){
            v[i-1]=i*v[i-2];
        }
        
        assert(k<=v[n-1]);
        
        vector<bool> used(n,false);
        
        stringstream ss;
        
        for(int i = 0; i < v.size()-1 ; ++i){
            int rank = (k-1) / v[v.size()-i-2];
            k -= rank*v[v.size()-i-2];
            int digit = findkthSmall(used,rank+1);
            ss << digit;
        }
        
        int digit = findkthSmall(used,1);
        ss << digit;
         
        return ss.str();
        
        //solution based on next_permutation
        /*
        vector<int> v(n,0);
        for(int i = 1; i <= n ; ++i){
            v[i-1]=i;
        }
        
        int i = 0;
        while( i++ != k){
            nextPermutation(v);
        }
        
        stringstream ss;
        for(int i = 1; i <= n ; ++i){
            ss << v[i-1];
        }
        
        return ss.str();
        */
    }
    
    void nextPermutation(vector<int> &num) {
        
        if(num.size()==0||num.size()==1)
            return;
        
        int i = num.size()-2;
        for( ; i>=0; --i){
            if(num[i]<num[i+1])
                break;
        }
        
        //rollback
        if(i==-1){
            reverse(num.begin(),num.end());
            return;
        }
        
        int j = i+1;
        while(j<num.size()){
            if(num[j]<=num[i])
                break;
            ++j;
        }
        
        swap(num[i],num[j-1]);
        reverse(num.begin()+i+1, num.end() );
        
    }
    
};