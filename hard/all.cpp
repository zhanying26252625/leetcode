/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 class Solution {
public:
    //O(N) space
    /*
    vector<int> postorderTraversal(TreeNode *root) {
             
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        unordered_set<TreeNode*> cache;
        
        while(curNode||!s.empty()){
            
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                curNode = s.top();
                s.pop();
                if(curNode->right&&cache.count(curNode->right)==0){ //if right is not visited
                    s.push(curNode);
                    curNode = curNode->right;
                }
                else{ //if right is already visited
                    v.push_back(curNode->val);
                    cache.insert(curNode);
                    curNode = NULL;
                }
            }
            
        }
        
        return v;    
    }
    */
    
    vector<int> postorderTraversal(TreeNode *root) {
             
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        TreeNode* preNode = NULL;
        
        while(curNode||!s.empty()){
            
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                curNode = s.top();
                s.pop();
                if( curNode->right==NULL||preNode==curNode->right ){ //if right is visited
                    v.push_back(curNode->val);
                    preNode = curNode;
                    curNode = NULL;
                }
                else{
                    s.push(curNode);
                    curNode = curNode->right;
                }
            }
            
        }
        
        return v;    
    }
    
};

//-----------------------------

/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
class Solution {
public:

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if(node==NULL){
            return NULL;
        }
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cache;
        cache[node] = new UndirectedGraphNode(node->label);
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            for(int i = 0; i < n->neighbors.size(); ++i ){
                UndirectedGraphNode* nb = n->neighbors[i];
                if( !cache.count(nb) ){
                    cache[nb] = new UndirectedGraphNode(nb->label);
                    (cache[n]->neighbors).push_back(cache[nb]);
                    q.push(nb);
                }
                else{

                    (cache[n]->neighbors).push_back(cache[nb]);
                }
                
            }
        }
        
        return cache[node];
    }
    
    
};

//-----------------------------

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    //O(N), not O(NlgN)
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            ++len;
        }
    
        TreeNode* root = buildBST(0,len-1,head);
        
        return root;
    }
    
     TreeNode* buildBST(int b ,int e, ListNode*& head){
         if(b<=e){
             int m = b + (e-b)/2;
             TreeNode* n = new TreeNode(0);
             n->left = buildBST(b,m-1,head);
             n->val=head->val;
             head=head->next;
             n->right = buildBST(m+1,e,head);
             
             return n;
         }
         return NULL;
     }
    
};








//-----------------------------

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList2(head);
    }
    
    //O(1) space, very tricky
    RandomListNode *copyRandomList2(RandomListNode *head) {
        //stage1
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        //stage2
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        //stage3
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
        
    }
    
    //O(N) space
    RandomListNode *copyRandomList1(RandomListNode *head) {
        
        if(!head)
            return NULL;
            
        unordered_map<RandomListNode* , RandomListNode*> cache;
        cache[NULL]=NULL;
        
        RandomListNode* cur = head;
        while(cur){
            RandomListNode* copy = new RandomListNode(cur->label);
            cache[cur]=copy;
            cur=cur->next;
        }
        
        cur = head;
        while(cur){
            RandomListNode* copy = cache[cur];
            copy->next = cache[cur->next];
            copy->random = cache[cur->random];
            cur=cur->next;
        }
        
        return cache[head];
        
    }
};

//-----------------------------

/*
Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:

   int divide(int dividend, int divisor) {
       
        assert(divisor != 0);
        
        bool flag = dividend > 0 && divisor < 0 || 
                    dividend < 0 && divisor > 0;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;
        while (dividendll >= divisorll)
        {
            long long div = divisorll;
            int quot = 1;
            while ((div << 1) <= dividendll) {
                div <<= 1;
                quot <<= 1;
            }
            dividendll -= div;
            res += quot;
        }
        
        return flag ? -res : res;
    }
	
	int divide1(int dividend, int divisor) {
        
        int neg = 1;
        if( (dividend>0) ^ (divisor>0) )
            neg = -1;
        
        long long dividend1 = abs((long long)dividend);
        long long divisor1 = abs((long long)divisor);
        
        int ret = 0;
        
        while(dividend1>=divisor1){
            
            int j = 0;
            while(dividend1 >= divisor1<<(j+1))
                ++j;
            
            dividend1 -= divisor1<<j;
            ret += 1<<j;
        }
        
        return ret*neg;
    }
};

//-----------------------------

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        vector<Interval> newV;
        
        if(intervals.size()==0){
            newV.push_back(newInterval);
            return newV;
        }
        
        int i = 0;
        bool used = false;
        for( ; i < intervals.size(); ++i ){
            Interval& interval = intervals[i];
            if(interval.end < newInterval.start){
                newV.push_back(interval);
            }
            else if(interval.start > newInterval.end){
                used = true;
                newV.push_back(newInterval);
                break;
            }
            else{
                int newStart = min(interval.start, newInterval.start);
                int newEnd = max(interval.end, newInterval.end);
                int j = i+1;
                while( j < intervals.size() ){
                    Interval& interval = intervals[j];
                    if(newEnd>=interval.start){
                        ++j;
                        newEnd = max(interval.end, newEnd);
                    }
                    else{
                        break;
                    }
                }
                
                used = true;
                newV.push_back(Interval(newStart,newEnd));
                i=j;
                break;
            }
        }
        
        if(i<intervals.size()){
            copy(intervals.begin()+i,intervals.end(),back_inserter(newV));
        }
        
        if( used != true){
            newV.push_back(newInterval);
        }
        
        return newV;
    }
    
};

//-----------------------------

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:

    //reduce exponetial to polynomial
    
    //dp1
    unordered_set<string> bad;
    
    bool isInterleave(string s1, string s2, string s3) {
        static string BAD("#_#");
        if(s1.size()+s2.size()!=s3.size())
            return false;
        
        if(s1=="") return s2==s3;
        if(s2=="") return s1==s3;
        
        if(bad.count(s1+BAD+s2+BAD+s3))
            return false;
            
        if(s1[0]==s3[0] && isInterleave(s1.substr(1),s2,s3.substr(1)) )
            return true;
        
        if(s2[0]==s3[0] && isInterleave(s1,s2.substr(1),s3.substr(1)) )
            return true;
            
        bad.insert(s1+BAD+s2+BAD+s3);
        return false;
        
    }

    //dp2
    bool isInterleave2(string & s1, string & s2, string & s3) {
        int M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        vector<vector<bool> > dp(M + 1, vector<bool>(N + 1, 0));
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = (s2[j - 1] == s3[j - 1]) && dp[i][j - 1];
                else if (j == 0) dp[i][j] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][j];
                else dp[i][j] = ((s2[j - 1] == s3[i + j - 1]) && dp[i][j - 1]) || ((s1[i - 1] == s3[i + j - 1]) && dp[i - 1][j]);
            }
        }
        return dp[M][N];
    }    
};


//-----------------------------

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses2(s);
    }

    int longestValidParentheses1(string & s) {
        int N = s.size(), res = 0, last = -1;
        stack<int> stk;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
                continue;
            }

            if (stk.empty()) {
                last = i; //remember where the latest valid position starts
            }
            else {
                stk.pop();
                res = max(res, stk.empty() ? (i - last) : (i - stk.top()));
            }
        }
        return res;
    }

    int longestValidParentheses2(string & s) {
        int N = s.size();
        return max(longestValidParenthesesHelper(s, '(', 0, N, 1), //(((((((((((((((()
            longestValidParenthesesHelper(s, ')', N - 1, -1, -1)); //())))))))))))))))
    }

    int longestValidParenthesesHelper(string & s, char c, int start, int end, int step) {
        int res = 0, counter_c = 0, pair = 0; // counts of c, and valid pairs
        for (int i = start; i != end; i += step) {
            if (s[i] == c) counter_c++ ;
            else counter_c--, pair++;
            if (counter_c == 0) res = max(res, pair*2);
            else if (counter_c < 0) counter_c = 0, pair = 0;
        }
        return res;
    }
};

//-----------------------------

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
class Solution {
public:

    int maxPoints(vector<Point> &points) {
        
        if(points.size()<=2)
            return points.size();
            
        int maxPoints = 2;
        
        for(int i = 0; i < points.size()-1; ++i){
            
            Point& src = points[i];
            //slope <-> points except src
            unordered_map<double, int> cache;
            cache.clear();
            //number of points same as src
            int duplicates = 1;
            
            for(int j = i + 1 ; j < points.size(); ++j){
                
                Point& dest = points[j];
                
                if(dest.x==src.x&&dest.y==src.y){
                    ++duplicates;
                    continue;
                }
                
                double slope = 0.0;
                if(src.x==dest.x)
                    slope = (double)INT_MAX;
                else
                    slope = (double)(dest.y-src.y)/(double)(dest.x-src.x);
                
                if(cache.count(slope)==0)
                    cache[slope]=1;
                else
                    cache[slope]++;
            }
            
            //update local max
            int count = 0;
            unordered_map<double,int >::iterator iter = cache.begin();
            while(iter != cache.end()){
                count = max(iter->second,count);
                ++iter;
            }
            
            //update global max
            maxPoints = max(maxPoints, count+duplicates );
        }
 
        return maxPoints;
    }
    
};

//-----------------------------

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/


class Solution {
public:

      string minWindow(string S, string T) {
        int needToFind[256] = {0};
        int hasFound[256] = {0};
        size_t count = 0;
        for (size_t i = 0; i < T.size(); i++)
            needToFind[(int)T[i]]++;

        string res = "";
        int min = INT_MAX;
        for (size_t begin = 0, end = 0; end < S.size(); end++) {
            if (needToFind[(int)S[end]] == 0) continue;
            hasFound[(int)S[end]]++;
            if (hasFound[(int)S[end]] <= needToFind[(int)S[end]]) count++;

            if (count == T.size()) {
                while (needToFind[(int)S[begin]] == 0 || hasFound[(int)S[begin]] > needToFind[(int)S[begin]]) {
                    if (hasFound[(int)S[begin]] > needToFind[(int)S[begin]]) hasFound[(int)S[begin]]--;
                    begin++;
                }

                int len = end - begin + 1;
                if (len < min) {
                    min = len;
                    res = S.substr(begin, len);
                }
            }
        }
        return res;
    }
    
};


//-----------------------------

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

//O(N^3) with cache, otherwise O(2^N)

class Solution {
public:
    vector<vector<string>> partition(string s) {
        //return partition1(s);
        return partition2(s);
    }
    
    //Top-down DP
    vector<vector<string>> vv;
    vector<vector<string>> partition1(string s) {
        if(s=="")
            return vv;
        vector<string> v;    
        partitionHelper(v,s);
        return vv;
    }
    
    void partitionHelper(vector<string> v, string s){
        if(s==""){
            vv.push_back(v);
            return ;
        }
        
        for(int i = 1; i <= s.size(); ++i){
            string prefix = s.substr(0,i);
            string suffix = s.substr(i);
            if(isPalindrome(prefix)){
                v.push_back(prefix);
                partitionHelper(v,suffix);
                v.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s){
        static unordered_map<string,bool> cache; // cache palindrom substring
        if(s=="")
            return true;
        if(cache.count(s)>0)
            return cache[s];
        for(int i = 0 , j = s.size()-1; i<=j; ++i,--j ){
            if(s[i]!=s[j]){
                cache[s]=false;
                return false;
            }
        }
        cache[s]=true;
        return true;
    }
    
    //Bottom-up DP
    vector<vector<string>> partition2(string s) {
        vector<vector<string>> vv;
        if(s=="")
            return vv;
        int N=s.size();
        vector<vector<bool> > dp1(N,vector<bool>(N,false) );//cache isPalindrome
        vector<vector<vector<string> > > dp2(N, vector<vector<string> >());//cache intermediate results
        
        for(int i = 0; i < N; ++i){
            for(int j = i ;j >= 0 ; --j){
                if(s[i]==s[j]&&(i-j<2||dp1[j+1][i-1])){ // if it palindrome
                    dp1[j][i]=true;
                    int len = i-j+1;
                    if(j==0){
                        dp2[i].push_back(vector<string>(1, s.substr(0, len)));
                    }
                    else{
                        for (int k = 0; k < dp2[j-1].size(); ++k ) {
                            vector<string> p = dp2[j-1][k];
                            p.push_back(s.substr(j, len));
                            dp2[i].push_back(p);
                        }
                    }
                }
            }
        }
        
        return dp2[N-1];
    }
    
};





//-----------------------------

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:

    int minCut(string s) {
        if(s.size()<2)
            return 0;

        int N = s.size();
        vector<vector<bool> > dp(N,vector<bool>(N,false) ); //cache palindrome substrs
        vector<int> minCuts(N,INT_MAX); // cache intermediate min cuts

        for(int i = 0; i < N; ++i){
            for(int j = i ;j >= 0 ; --j){
                if(s[j]==s[i]&&(i-j<2||dp[j+1][i-1])){
                    dp[j][i]=true;
                    if(j==0){
                        minCuts[i] = 0;
                    }
                    else{
                        minCuts[i] = std::min(minCuts[i],minCuts[j-1]+1);
                    }
                }
            }
        }
        return minCuts[N-1];
    }
};


//-----------------------------

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

//-----------------------------

/*
Implement pow(x, n).
*/


class Solution {
public:

    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }
    
};

//-----------------------------

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:

   bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if (*p == '\0') return *s == '\0';

        if (*(p+1) != '*') {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    };
    
    bool isMatch1(const char *s, const char *p) {
        
        string str(s);
        string pattern(p);
        
        isMatch1(str,pattern);
    }

    bool isMatch1(string s, string p){
        
            if( p=="" )
                return s=="";
        
            if(p[1]!='*'){
                if(s[0]==p[0]|| (p[0]=='.' && s!="") )
                    return isMatch1(s.substr(1),p.substr(1));
                return false;
            }
            else{
                
                if( isMatch1(s,p.substr(2)) )
                    return true;
                    
                for(int i = 0; i<s.size(); ++i){
                    if(s[i]==p[0]|| p[0]=='.'){
                        if(isMatch1(s.substr(i+1),p.substr(2)))
                            return true;
                    }
                    else{
                        break;
                    }
                }
                
                return false;
            }
        
    }
    
};

//-----------------------------

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
class Solution {
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if(s.size()<4||s.size()>12)
            return v;
        vector<string> cur;   
        restoreIpAddresses(v,s,cur);
        return v;
    }
    
    void restoreIpAddresses(vector<string>& v, string s, vector<string>& cur){
        
        if(cur.size()==4&&s==""){
            stringstream ss;
            for(int i = 0 ; i < cur.size(); ++i)
                ss<<'.'<<cur[i];
            v.push_back(ss.str().substr(1));
            return;
        }
        
        if(cur.size()==4) return;
        
        int len = std::min(3,(int)s.size());
        for(int i = 1; i <= len; ++i){
            string prefix = s.substr(0,i);
            if(isValid(prefix)){
                cur.push_back(prefix);
                restoreIpAddresses(v,s.substr(i),cur);
                cur.pop_back();
            }
        }
    }
    
    bool isValid(string& s){
        if(s=="") return false;
        if(s.size()==1) return s[0]>='0'&&s[0]<='9';
        if(s.size()==2) return atoi(s.c_str())>=10;
        if(s.size()==3) return atoi(s.c_str())>=100&&atoi(s.c_str())<=255;
        return false;
    }
    
};




//-----------------------------

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:

    void rotate(vector<vector<int> > &matrix) {
        if (matrix.empty()) return;
        int N = matrix.size();
        for (int i = 0; i <= N/2; i++) {
            int first = i, last = N-i-1;
            for (int j = first; j < last; j++) {
                int top = matrix[first][j], offset = j-first;
                matrix[first][j] = matrix[last-offset][first];
                matrix[last-offset][first] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[j][last];
                matrix[j][last] = top;
            }
        }  
    }
	
	/*
	void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        if(N<=1)
            return;
        
        for(int i = 0; i < N/2; ++i){
            int b = i;
            int e = N-i-1;
            for(int l = 0; b+l<e ; ++l){
                int tmp = matrix[b][b+l];
                matrix[b][b+l] = matrix[e-l][b];
                matrix[e-l][b] = matrix[e][e-l];
                matrix[e][e-l] = matrix[b+l][e];
                matrix[b+l][e] = tmp;
            }
        }
        return;
        
        
    }
	*/
    
};

//-----------------------------

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers_1(root);
    }
    
    //recursive
    int sumNumbers_1(TreeNode *root) {
        int sum = 0;
        sumNumbersRe(root, 0, sum);
        return sum;
    }
    
    void sumNumbersRe(TreeNode *node, int num, int &sum) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { 
            sum += num;
            return;
        }
        sumNumbersRe(node->left, num, sum);
        sumNumbersRe(node->right, num, sum);
    }
    
    //iterative
    int sumNumbers_2(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            TreeNode *node = q.front().first;
            int sum = q.front().second * 10 + node->val;
            q.pop();
            if (!node->left && !node->right)
            {
                res += sum;
                continue;
            }
            if (node->left)
                q.push(make_pair(node->left, sum));
            if (node->right)
                q.push(make_pair(node->right, sum));
        }
        return res;
    }
};

//-----------------------------

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

class Solution {
public:

    bool isNumber(const char* s) {
        // trim leading/trailing spaces
        while (*s != '\0' && isspace(*s)) s++;
        if (*s == '\0') return false;
        const char *e = s + strlen(s) - 1;
        while (e > s && isspace(*e)) e--;
        // skip leading +/-
        if (*s == '+' || *s == '-') s++;

        bool num = false; // is a digit
        bool dot = false; // is a '.'
        bool exp = false; // is a 'e'
        while (s != e + 1) {
            if (*s >= '0' && *s <= '9') {
                num = true;
            }
            else if (*s == '.') {
                if(exp || dot) return false;
                dot = true;
            }
            else if (*s == 'e') {
                if(exp || num == false) return false;
                exp = true;
                num = false;
            }
            else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e') return false;
            }
            else {
                return false;
            }
            s++;
        }
        return num;
    }
	
	
	   //state machine
	   bool isNumber1(const char *s) {
        if(*s==0) return false;
        enum Action {INVALID=0, SPACE=1, SIGN=2, DIGIT=3, DOT=4, EXPONENT=5};
        const int N = 6;
        //[state][action]
        int transTable[][N] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        int state = 0;
        while(*s){
            Action act = INVALID;
            if (*s == ' ')
                act = SPACE;
            else if (*s == '+' || *s == '-')
                act = SIGN;
            else if (isdigit(*s))
                act = DIGIT;
            else if (*s == '.')
                act = DOT;
            else if (*s == 'e')
                act = EXPONENT;
            state = transTable[state][act];
            if (state == 0) return false;
            s++;
        }
        
        bool validStates[]={0,0,0,1,0,0,1,1,1};
        return validStates[state];
    }
	
};

//-----------------------------

/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
/*
Analysis:

For each element in s
If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
If not match, then we check if there is a * previously showed up,
       if there is no *,  return false;
       if there is an *,  we set current p to the next element of *, and set current s to the next saved s position

abed
?b*d**

a=?, go on, b=b, go on,
e=*, save * position star=3, save s position ss = 3, p++
e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
d=d, go on, meet the end.
check the rest element in p, if all are *, true, else false;
*/
    //very clever
    bool isMatch(const char *s, const char *p) {

        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }
    
//Timeout, so many recursion even if optimized
/*
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0') {
            if (*p == '\0') return true;
            if (*p == '*') return isMatch(s,p+1);
            return false;
        }
        if (*p == '\0') return false;
        if (*p == '?' || *p == *s) return isMatch(s+1, p+1);
        if (*p=='*'){ 
            //advance * as much as possible
            while(*p=='*')
                ++p;
            if(*p=='\0')
                return true;
            --p;
            return isMatch(s+1,p) || isMatch(s, p+1);
        }
        
        return false;
    }
*/

};

//-----------------------------

/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:

    unordered_set<string> bad;
    
	//DP top-down O(N^2)
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s=="")
            return true;
        if(dict.count(s)>0)
            return true;
        if(bad.count(s)>0)
            return false;
        
        for(int end = 1; end<=s.size();++end){
            string prefix = s.substr(0,end);
            string postfix = s.substr(end);
            if(dict.count(prefix)>0 && wordBreak(postfix,dict)){
                return true;
            }
        }
        
        bad.insert(s);
        return false;
    }
	
	//DP bottom-up O(N^2)
	/*
	bool wordBreak(string s, unordered_set<string> &dict) {
        if(s=="")
            return false;
            
        vector<bool> can(s.size()+1,false);
        can[0]=true;
        for(int i = 1 ; i <= s.size(); ++i){
            for(int j = i; j>=1; --j){
                if(can[j-1]&&dict.count(s.substr(j-1,i-j+1))>0) { can[i]=true;break; }
            }
        }
        return can[s.size()];
    }
	*/
};

//-----------------------------

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/
class Solution {
    
public:

class Solution {
public:

    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        if(s==""||dict.size()==0)
            return vector<string>();
        
        // dp[i][j] means when string is at size of i , we have a valid word of length j before it
        vector<vector<int> > dp(s.size()+1,vector<int>());
        
        dp[0].push_back(0); //no valid word before it
        
        for(int i = 1; i <= s.size(); ++i){ //cur size
            for(int j = i; j >= 1 ; --j){ //pre len
                if( dict.count(s.substr(i-j,j))>0 && dp[i-j].size()>0 ){
                    dp[i].push_back(j); // record word len
                }
            }
        }
        
        return buildVec(s,s.size(),dp);
    }
    
    vector<string> buildVec(const string& str, int len, const vector<vector<int> >& dp){
        
        vector<string> v;
        
        for(int i = 0; i < dp[len].size(); ++i){
            int wordLen = dp[len][i];
            if(wordLen==len){
                v.push_back(str);
            }
            else{
                vector<string> pres = buildVec(str.substr(0,len-wordLen),len-wordLen,dp);
                for(int j = 0 ; j < pres.size(); ++j){
                    v.push_back(pres[j]+" " + str.substr(len-wordLen) );
                }
            }
        }
        
        return v;
    }
    
};


/*
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<vector<int> > dp(N+1, vector<int>()); // dp[i][j] means ends at i, previous valid end at j
        dp[0].push_back(0);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= i; j++)
                if (dp[i-j].size() && (dict.find(s.substr(i-j, j)) != dict.end()))
                    dp[i].push_back(i-j);
        return wordBreakHelper(s, dp, N);
    }

    vector<string> wordBreakHelper(string & str, vector<vector<int> > & dp, int i) {
        vector<string> res;
        for (int j = 0; j < (int)dp[i].size(); j++) {
            if (dp[i][j] == 0) {
                res.push_back(str.substr(0, i));
            }
            else {
                string tmp = str.substr(dp[i][j], i-dp[i][j]);
                vector<string> sub = wordBreakHelper(str, dp, dp[i][j]);
                for (int k = 0; k < (int)sub.size(); k++) {
                    res.push_back(sub[k]+" "+tmp);
                }
            }
        }

        return res;
    }
 */   
};

//-----------------------------

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
	
	//used a different hash to track nodes which were visited before
	/*
	class Solution {
	public:

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start==end)
            return 0;
            
        typedef pair<string,int> Pair;
        unordered_set<string> used;
        queue<Pair> q;
        q.push(make_pair(start,1));
        used.insert(start);
        
        while(!q.empty()){
            Pair p = q.front();
            q.pop();
            if(p.first==end) return p.second;
            vector<string> neighbors = getNeighbors(p.first,dict);
            for(int i = 0; i < neighbors.size(); ++i){
                if(used.count(neighbors[i])==0){
                    used.insert(neighbors[i]);
                    q.push(pair<string,int>(neighbors[i],p.second+1));
                }
            }
        }
        return 0;
    }
    
    vector<string > getNeighbors(const string& s,  unordered_set<string> &dict){
        
        vector<string > neighbors;
        string start(s);
        for(int i = 0; i < start.size(); ++i){
            for(int j = 'a' ; j <= 'z' ; ++j){
                start[i] = j;
                if( dict.count(start) > 0){
                    neighbors.push_back(start);
                }
            }
            start = s;
        }
        return neighbors;
    }
    
};
	*/
    
};

//-----------------------------

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

    vector<string > getNeighbors(const string& s,  unordered_set<string> &dict){
        vector<string > neighbors;
        string start(s);
        for(int i = 0; i < start.size(); ++i){
            for(int j = 'a' ; j <= 'z' ; ++j){
                start[i] = j;
                if(start!=s && dict.count(start) > 0){
                    neighbors.push_back(start);
                }
            }
            start = s;
        }
        return neighbors;
    }
    
    vector<vector<string> > res;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string> > graph;//build graph from start to end
        unordered_set<string> visited; //track visited
        unordered_set<string> curr, prev; // bfs levels
        prev.insert(start);
        visited.insert(start);
        //BFS to build graph
        while(!prev.empty()){
            //mark prev visited
            for(unordered_set<string>::iterator iter = prev.begin(); iter != prev.end(); ++iter){
                visited.insert(*iter);
            }
            //get curr level
            for(unordered_set<string>::iterator iter = prev.begin(); iter != prev.end(); ++iter){
                const string& preStr = *iter;
                vector<string> neighbors = getNeighbors(preStr,dict);
                for(int i = 0; i < neighbors.size(); ++i){
                    string& curStr = neighbors[i];
                    if(visited.count(curStr)==0){ // not visited before
                        curr.insert(curStr); 
                        graph[preStr].push_back(curStr);
                        //visited.insert(curStr);//Don't mark visited here, otherwise would block other paths
                    }
                }
            }
            if(curr.size()==0) return res; //not found
            if(curr.count(end)>0) break; //found
            prev = curr;
            curr.clear();
        }
        
        //DFS to find all paths
        vector<string> path;
        getPath(start, end, graph, path);
        return res;
    }
    
    void getPath(string& start, string& end, unordered_map<string,vector<string> >& graph, vector<string> & path) {
        path.push_back(start);
        if (start == end) {
            res.push_back(vector<string>(path.begin(), path.end()));
        }
        else {
            vector<string>& childs = graph[start];
            for (int i = 0; i < childs.size(); ++i  ) {
                getPath(childs[i], end, graph, path);
            }
        }
        path.pop_back();
    }
};



//-----------------------------

