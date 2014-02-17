/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:

    struct MyComp{
      bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
          return p1.first < p2.first;
      }  
    };
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        assert(numbers.size()>=2);
        
        vector<int> v(2,0);
        vector<pair<int,int> > pairs;
        for(int i = 0; i<numbers.size();++i){
            pairs.push_back(pair<int,int>(numbers[i],i+1));
        }
        
        sort(pairs.begin(),pairs.end(),MyComp());
        
        for(int i = 0, j = pairs.size()-1; i<j ; ){
            int vi = pairs[i].first;
            int vj = pairs[j].first;
            if( vi + vj == target){
                v[0]=pairs[i].second;
                v[1]=pairs[j].second;
                break;
            }
            else if( vi + vj > target){
                --j;
            }
            else{
                ++i;
            }
        }
        
        if(v[0]>v[1])
            swap(v[0],v[1]);
            
        return v;
                
    }
    
};

//-----------------------------

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;  
        int N = num.size();
        if (N < 3) return res;

        sort(begin(num), end(num));
        for (int k = 0; k < N-2; k++) {
            if (k > 0 && num[k-1] == num[k]) continue; //remove any duplicates
            int i = k+1, j = N-1;
            while (i < j) {
                int sum = num[k]+num[i]+num[j];
                if (sum < 0) i++;
                else if (sum > 0) j--;
                else {
                    vector<int> sub;
                    sub.push_back(num[k]);
                    sub.push_back(num[i]);
                    sub.push_back(num[j]);
                    res.push_back(sub);
                    do { i++; } while (i < j && num[i-1] == num[i]); //remove any duplicates
                    do { j--; } while (i < j && num[j] == num[j+1]);
                }

            }
        }
        return res;
    }
};

//-----------------------------

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:

    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size();
        sort(begin(num), end(num));
        int res = INT_MAX;
        for (int k = 0; k < N-2; k++) {
            int i = k+1, j = N-1;
            while (i < j) {
                int sum = num[i]+num[j]+num[k];
                if (sum == target) return sum;
                if (abs(sum-target) < abs(res-target)) res = sum;
                if (sum > target) j--;
                else i++;
            }
        }
        return res;
    }
    
};

//-----------------------------

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int N = num.size();
        if (N < 4) return res;
        sort(begin(num), end(num));
        for (int i = 0; i < N-3; i++) {
            if (i > 0 && num[i-1] == num[i]) continue;
            for (int j = i+1; j < N-2; j++) {
                if (j > i+1 && num[j-1] == num[j]) continue;
                int l = j+1;
                int r = N-1;
                while (l < r) {
                    int sum = num[i]+num[j]+num[l]+num[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        vector<int> sub;
                        sub.push_back(num[i]);
                        sub.push_back(num[j]);
                        sub.push_back(num[l]);
                        sub.push_back(num[r]);
                        res.push_back(sub);
                        do { l++; } while (l < r && num[l-1] == num[l]);
                        do { r--; } while (l < r && num[r] == num[r+1]);
                    }
                }
            }
        }

        return res;
    }
};

//-----------------------------

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:

    string addBinary(string a, string b) {
        
        if(a=="0"){
            return b;
        }
        if(b=="0"){
            return a;
        }
        
        string c(max(a.size(),b.size())+1,'0');
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        a += string(c.size()-a.size(),'0');
        b += string(c.size()-b.size(),'0');
        
        int carry = 0;
        for(int i = 0 ; i < c.size(); ++i){
            
            int ai = a[i]-'0';
            int bi = b[i]-'0';
            
            if( (ai^bi^carry)
                c[i] = '1';
            else
                c[i] = '0';
                
            if(ai&&bi || ai&&carry || bi&&carry)
                carry = 1;
            else
                carry = 0;
        }
        
        if(c[c.size()-1]=='0')
            c = c.substr(0,c.size()-1);

        reverse(c.begin(),c.end());
        
        return c;
    }
    
};

//-----------------------------

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       ListNode *start=NULL, *tail=NULL;
       ListNode *L1=l1, *L2=l2;
       int carry=0;
       int sum=0;
       while(L1!=NULL||L2!=NULL||carry!=0)
       {
           int num1=(L1==NULL)? 0 :L1->val;
           int num2=(L2==NULL)? 0 :L2->val;
           sum=num1+num2+carry;
           carry=sum/10;
           sum%=10;
           
		   //we can use a dummy head node to get-rid-of this if-else
           if(start==NULL)
           {
               start=new ListNode(sum);
               tail=start;
           }
           else
           {
               tail->next=new ListNode(sum);
               tail=tail->next;
           }
           
           L1=(L1==NULL)? NULL :L1->next;
           L2=(L2==NULL)? NULL :L2->next;
       }
       
       return start;
    }
};

//-----------------------------

/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:

    vector<string> anagrams(vector<string> &strs) {
        
        map<string, vector<string> > buffer;
        for (int i = 0; i < strs.size(); i++) {
            string copy(strs[i]);
            sort(copy.begin(), copy.end());
            buffer[copy].push_back(strs[i]);
        }
        vector<string> res;
        map<string, vector<string> >::iterator it = buffer.begin();
        while (it != buffer.end()) {
            vector<string> sub = it->second;
            if (sub.size() > 1)
                for (int i = 0; i < sub.size(); i++)
                    res.push_back(sub[i]);
            it++;
        }
        return res;
    }
};

//-----------------------------

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:

    int atoi(const char *str) {
        if (!str) return 0;
        while (*str == ' ') str++;
        bool positive = true;
        if (*str == '+' || *str == '-') {
            positive = *str == '+';
            str++;
        }
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        res = positive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
    
};

//-----------------------------

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

    int isBalancedTree(TreeNode *root){
        
        if(root==NULL) return 0;
        
        int left = isBalancedTree(root->left);
        if( -1 == left )
            return -1;
        
        int right = isBalancedTree(root->right);
        if( -1 == right )
            return -1;

        if(abs(left-right)>1)
            return -1;
            
        return max(left,right)+1;
    }

    bool isBalanced(TreeNode *root) {

        return isBalancedTree(root)>=0;
    }
};

//-----------------------------

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
            return 0;
        
        int min = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i]<min){
                min = prices[i];
            }
            else{
                maxProfit = max(maxProfit, prices[i]-min);
            }
        }
        return maxProfit;
    }
};

//-----------------------------

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        
        int res = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            int d = prices[i]-prices[i-1];
            if (d > 0) res += d;
        }
        return res;
    }
    
};

//-----------------------------

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:

    int maxProfit(vector<int> &prices) {
        
        if(prices.size()<2){
            return 0;
        }
        
        vector<int> profitUtil(prices.size(),0);
        vector<int> profitFrom(prices.size(),0);
        
        int min = prices[0];
        int profit = 0;
        for(int i= 1; i < prices.size(); ++i){
            if(prices[i]<min){
                min=prices[i];
            }
            else{
                profit = std::max(profit,prices[i]-min);
            }
            profitUtil[i] = profit; 
        }
        
        profit = 0;
        int max= prices[prices.size()-1];
        
        for(int i = prices.size()-2; i >=0 ; --i){
            if(prices[i]>max){
                max = prices[i];
            }
            else{
                profit = std::max(profit, max - prices[i]);
            }
            profitFrom[i] = profit;
        }
        
        //once transaction
        int maxOne = profit;
        
        //at most twice
        int maxTwo = 0;
        for(int i = 1; i < prices.size()-2; ++i){
            maxTwo = std::max(maxTwo, profitUtil[i]+profitFrom[i+1] );
        }
        
        return std::max(maxOne,maxTwo);
    }
    
};


//-----------------------------

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

    //iterative
    vector<int> inorderTraversal(TreeNode *root) {
        
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        
        while(curNode||!s.empty()){
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                TreeNode* n= s.top();
                s.pop();
                v.push_back(n->val);
                curNode=n->right;
            }
            
        }
        
        return v;
    }
};







//-----------------------------

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

    void levelOrder(TreeNode *root, vector<vector<int> >& vv, int depth){
        if(root==NULL)
            return;
            
        if(vv.size()<depth){
            vv.push_back(vector<int>());
        }
        
        vv[depth-1].push_back(root->val);
        levelOrder(root->left,vv, depth+1);
        levelOrder(root->right,vv, depth+1);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > vv;
        if(root==NULL)
            return vv;
            
        levelOrder(root, vv, 1);
        
        return vv;
    }
    
    //we can also use BFS, similar but simpler as Binary Tree Zigzag Level Order Traversal
};


//-----------------------------

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

    void levelOrder(TreeNode *root, vector<vector<int>* >& vv, int depth){
        
        if(root==NULL)
            return;
            
        if(vv.size()<depth){
            vv.push_back(new vector<int>());
        }
        
        vv[depth-1]->push_back(root->val);
        levelOrder(root->left,vv, depth+1);
        levelOrder(root->right,vv, depth+1);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        vector<vector<int>* > vv;

        levelOrder(root, vv, 1);
        
        //reverse order
        reverse(vv.begin(),vv.end());
        
        vector<vector<int> > retVV;
        for(int i = 0; i < vv.size(); ++i){
            retVV.push_back(*(vv[i]));
            delete vv[i];
        }
        
        return retVV;
    }
};

//-----------------------------

/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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

    //maxPath,maxHeight
    typedef pair<int,int> Val;
    
    int maxPathsumHelper(TreeNode* root, Val& v){
        
        int maxChildPath = INT_MIN;
        int maxRootPath = root->val;
        int maxHeight = root->val;
        
        if(root->left){
            Val leftV;
            maxPathsumHelper(root->left,leftV);
            if(leftV.second>0)
                maxRootPath += leftV.second;
                
            maxChildPath = max(maxChildPath, leftV.first);
            maxHeight = max(maxHeight,root->val+leftV.second);
        }
        
        if(root->right){
            Val rightV;
            maxPathsumHelper(root->right,rightV);
            if(rightV.second>0)
                maxRootPath += rightV.second;
                
            maxChildPath = max(maxChildPath,rightV.first);
            maxHeight = max(maxHeight,root->val+rightV.second);
        }
        
        v.first = max(maxChildPath,maxRootPath);
        v.second = maxHeight;

        return v.first;
    }
    
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
            
        Val v;
        maxPathsumHelper(root,v);
        return v.first;
    }
};


//-----------------------------

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
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode *root) {
        
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        
        while(curNode||!s.empty()){
            if(curNode){
                v.push_back(curNode->val);
                if(curNode->right)
                    s.push(curNode->right);
                curNode=curNode->left;
            }
            else{
                curNode= s.top();
                s.pop();
            }
            
        }
        
        return v; 
    }
};

//-----------------------------

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vv;
        if(root==NULL)
            return vv;
            
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        int level = 1;
        
        while(!q.empty()){
            TreeNode* n =  q.front();
            q.pop();
            --size;
            v.push_back(n->val);
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
                
            if(0==size){
                if(level%2==0){
                    reverse(v.begin(),v.end());
                }
                vv.push_back(v);
                v.clear();
                size = q.size();
                ++level;
            }
        }
        
        return vv;
    }
};

//-----------------------------

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:

    int candy(vector<int> &ratings) {
        
        vector<int> gives(ratings.size(),1);
        
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i]>ratings[i-1]){
                gives[i] = max(gives[i],gives[i-1]+1);
            }
        }
        
        for(int i = ratings.size() - 2; i >=0 ; --i){
            if(ratings[i]>ratings[i+1]){
                gives[i] = max(gives[i],gives[i+1]+1);
            }
        }
    
        int total = 0;
        for(int i = 0; i < ratings.size(); ++i){
            total += gives[i];
        }
        
        return total;
    }
    
};

//-----------------------------

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    unordered_map<int,int> cache;
    int climbStairs(int n) {
        if(n==0||n==1)
            return 1;
        
        if(cache.count(n))
            return cache[n];
        
        cache[n] = climbStairs(n-1) + climbStairs(n-2);
        return cache[n];
    }
};

/*
    int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1;
        int b = 2;
        int c;
        for (int i = 2; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
*/

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
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:

    vector<vector<int> > vv;
    
    void combinationSum(vector<int> &candidates, int target, int index, int sum, vector<int>& v){
        
        if(sum==target){
            vv.push_back(v);
            return;
        }
        
        if(sum>target||index>=candidates.size()){
            return;
        }
        
        v.push_back(candidates[index]);
        combinationSum(candidates,target,index,sum+candidates[index],v);
        v.pop_back();
        
        combinationSum(candidates,target,index+1,sum,v);
        
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        combinationSum(candidates,target,0,0,v);
        return vv;
    }
    
};

//-----------------------------

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]
*/


class Solution {
public:

    vector<vector<int> > vv;
    
    void combinationSum(vector<int> &candidates, int target, int index, int sum, 
                        vector<int>& v ,vector<bool>& used){
        
        if(sum==target){
            vv.push_back(v);
            return;
        }
        
        if(sum>target||index>=candidates.size()){
            return;
        }
        
        //previous same ones must be used if it exists
        bool flag = true;
        
        if( index!=0 && (candidates[index-1]==candidates[index] && used[index-1]==false ) ){
            flag = false;//previous same one is not used
        }
        
        if(flag){
            v.push_back(candidates[index]);
            used[index]=true;
            combinationSum(candidates,target,index+1,sum+candidates[index],v,used);
            v.pop_back();
            used[index]=false;
        }

        combinationSum(candidates,target,index+1,sum,v,used);
    }
    
    vector<vector<int> > combinationSum2(vector<int> & num, int target) {
        
        sort(num.begin(),num.end());
        vector<int> v;
        vector<bool> used(num.size(),false);
        combinationSum(num,target,0,0,v,used);
        return vv;
    }
    
};

//-----------------------------

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















//-----------------------------

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder.begin(), postorder.begin(), inorder.size());
    }

    TreeNode *buildTreeHelper(vector<int>::iterator inorder, vector<int>::iterator postorder, size_t n) {
        if (n == 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder + n, *(postorder+n-1));
        int idx = it - inorder;
        TreeNode* root = new TreeNode(*it);
        root->left = buildTreeHelper(inorder, postorder, idx);
        root->right = buildTreeHelper(inorder+idx+1, postorder+idx, n-idx-1);
        return root;
    }
};

//-----------------------------

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree
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
    
    TreeNode *buildTree(vector<int> &preorder, int preb, int pree,
                        vector<int> &inorder, int inb, int ine){
        
        if(preb>=pree)
            return NULL;
            
        int pivot = preorder[preb];
        int mid = inb;
        while(inorder[mid]!=pivot)
            ++mid;

        int leftSize = mid-inb;
        
        TreeNode* node = new TreeNode(pivot);
        
        node->left = buildTree(preorder,preb+1,preb+leftSize+1,inorder,inb,inb+leftSize);
        node->right = buildTree(preorder,preb+leftSize+1,pree,inorder,inb+leftSize+1,ine );
        
        return node;                 
    }
 
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        if(preorder.size()!=inorder.size())
            return NULL;
        if(preorder.size()==0)
            return NULL;
        //off by one convention
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
        
    }
};

//-----------------------------

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int N = height.size();
        if (N < 2) return 0;
        int i = 0, j = N-1, res = 0;
        while (i < j) {
            res = max(res, (j-i)*min(height[i], height[j]));
            if (height[i] < height[j]) {
                ++i;
            }
            else {
                --j;
            }
        }
        return res;
    }
};

//-----------------------------

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

    TreeNode *sortedArrayToBST(vector<int> &num, int b , int e) {
        if(b<=e){
            int m = b + (e-b)/2;
            TreeNode* n = new TreeNode(num[m]);
            n->left = sortedArrayToBST(num,b,m-1);
            n->right = sortedArrayToBST(num,m+1,e);
            return n;
        }
        return NULL;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num,0,num.size()-1);
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
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:

    string countAndSay(int n) {
        
        string s = "1";
        
        for(int i = 1; i < n; ++i){
            
            stringstream ss;
            
            int b = 0;
            int e = 1;
            
            while(e!=s.size()){
                if(s[e]!=s[b]){
                    ss << e-b << s[b];
                    b = e;
                }
                ++e;
            }
            ss << e-b << s[b];
            
            s = ss.str();
        }
        
        return s;
    }
};

//-----------------------------

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution {
public:

    int numDecodings(string s) {
        
        if(s==""||s[0]=='0')
            return 0;
        vector<int> ways(s.size()+1,0);
        ways[0]=1;
        ways[1]=1;
        for(int i = 1; i < s.size(); ++i){
            if(s[i]>'0') ways[i+1] += ways[i];
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')) ways[i+1] += ways[i-1];
        }
        
        return ways[s.size()];
    }
    
};

//-----------------------------

/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution {
public:

    int numDistinct(string S, string T) {
        
        vector<vector<int> > dp(S.size()+1,vector<int>(T.size()+1,0) );
       
        for(int i =0 ;i < S.size(); ++i){
            dp[i][0]=1;
        }
        
        for(int i = 1 ; i <= S.size() ; ++i ){
            for(int j = 1; j <= T.size(); ++j){
                int num = dp[i-1][j];
                if(S[i-1]==T[j-1]){
                    num += dp[i-1][j-1];
                }
                dp[i][j] = num;
            }
        }
        
        return dp[S.size()][T.size()];
        
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

//-----------------------------

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:

    int evalRPN(vector<string> &tokens) {
        
        stack<int> s;
        
        for(int i = 0; i < tokens.size(); ++i){
            
            if(tokens[i]=="+"||
               tokens[i]=="-"||
               tokens[i]=="*"||
               tokens[i]=="/"){
                   int second = s.top();
                   s.pop();
                   int first = s.top();
                   s.pop();
                   if(tokens[i]=="+"){
                       s.push(first+second);
                   }
                   else if(tokens[i]=="-"){
                       s.push(first-second);
                   }
                   else if(tokens[i]=="*"){
                       s.push(first*second);
                   }
                   else{
                       s.push(first/second);
                   }
            }
            else{
                s.push(atoi(tokens[i].c_str()));
            }
        }
        
        return s.top();
    }
    
};

//-----------------------------

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:

    int firstMissingPositive(int A[], int n) {
        
        for(int i = 0; i < n ; ++i){
            while( A[i]>0 && A[i]<=n && A[i]!=i+1 && A[i]!=A[ A[i]-1 ]){
                swap(A[i],A[ A[i]-1 ]);
            }
        }
        
        int i = 0; 
        while(A[i]==i+1)
            ++i;
        
        return i+1;
    }
    
};

//-----------------------------

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    
    TreeNode* preNode = NULL;
    
    void flatten(TreeNode *root) {
   
        if(root!=NULL){
            
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = NULL;
            root->right = NULL;
            
            if(preNode){
                preNode->right = root;
            }
            preNode = root;
            
            flatten(left);
            flatten(right);
        
        }

    }
    
};



















//-----------------------------

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:

    //O(N)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

        int gasSum = 0;
        int costSum = 0;
        int index = 0;
        int profit = 0;
        
        for(int i = 0 ; i < gas.size(); ++i){
            gasSum += gas[i];
            costSum += cost[i];
            profit += gas[i]-cost[i];
            if(gasSum<costSum){
                index = i + 1;
                gasSum = 0;
                costSum = 0;
            }    
        }
        
        if(profit<0)
            return -1;
        else
            return index;
        
    }
    
    
    //O(N^2)
    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        
        for(int i = 0; i < N; ++i){
            int gasSum=0;
            int costSum = 0;
            int len = 0;
            for(int j = i ;  len != N; ++len, ++j){
                if(j==N)
                    j=0;
                gasSum += gas[j];
                costSum += cost[j];
                if(gasSum<costSum) // can NOT do it
                    break;
            }
            
            if(len==N)
                return i;
        }
        
        return -1;
    }
    
};

//-----------------------------

/*
Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:

    void generateParenthesis(int pre, int post , string s, vector<string>& v){
        
        if(pre>post||pre<0||post<0){
            return;
        }
        
        if(pre==0&&post==0){
            v.push_back(s);
            return;
        }

        generateParenthesis(pre-1,post,s+"(",v);
        generateParenthesis(pre,post-1,s+")",v);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if(n==0)
            return v;
            
        string s;
        generateParenthesis(n,n,s,v);
        return v;
    }
    
};

//-----------------------------

/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

class Solution {
public:

    vector<int> grayCode(int n) {
        
        vector<int> v;
        v.push_back(0);
        
        int bit = 1;
        
        for(int i = 0; i < n; ++i){
            
            vector<int> reverseV(v.rbegin(),v.rend());
            for(int j = 0 ; j < reverseV.size(); ++j){
                v.push_back( reverseV[j] | bit );
            }
            
            bit <<= 1;
        }
        
        return v;
    
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
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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

    struct MyComp{
        
        bool operator()(const Interval& i1, const Interval& i2){
            return i1.start<i2.start;
        }    
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
            
        sort(intervals.begin(),intervals.end(),MyComp());
        
        vector<Interval> v;
        
        Interval curI = intervals[0];
        
        int index = 1;
        
        while(index<intervals.size()){
            
            Interval newI = intervals[index];
            
            if(newI.start<=curI.end){
                curI.end = max(curI.end, newI.end);
            }
            else{
                v.push_back(curI);
                curI = newI;
            }
            
            ++index;
        }
        
        v.push_back(curI);
        
        return v;
    }
};














//-----------------------------

/*
Sort a linked list using insertion sort.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:

    ListNode *insertionSortList(ListNode *head) {
        if(!head||!(head->next))
            return head;
        
        ListNode* nextNode = insertionSortList(head->next);
        return insert(head,nextNode);
    }
    
    ListNode* insert(ListNode* newNode, ListNode* head){
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre = &dummy;
        
        while(pre->next&&newNode->val>pre->next->val)
            pre=pre->next;
        
        newNode->next=pre->next;
        pre->next=newNode;
        return dummy.next;
    }
    
};

//-----------------------------

/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
public:
    map<int, string> dict;
    string intToRoman(int num) {
        dict.clear();
        dict[1] = "I";
        dict[4] = "IV";
        dict[5] = "V";
        dict[9] = "IX";
        dict[10] = "X";
        dict[40] = "XL";
        dict[50] = "L";
        dict[90] = "XC";
        dict[100] = "C";
        dict[400] = "CD";
        dict[500] = "D";
        dict[900] = "CM";
        dict[1000] = "M";
        string result = "";
        for (map<int, string>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++) {
            while (num >= it->first) {
                result += it->second;
                num -= it->first;
            }
        }
        return result;
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
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:

    unordered_map<int,bool> cache;
    //recursive
    bool canJump(const vector<int>& v, int curPos){
        
        if(curPos>=v.size()-1)
            return true;
            
        if(cache.count(curPos))
            return cache[curPos];
        
        int len = v[curPos];
        for(int i = 1; i<len; ++i){
            if(canJump(v,curPos+i)){
                cache[curPos]=true;
                return true;
            }
        }
        
        cache[curPos]=false;
        return false;
    }
    
    bool canJump(int A[], int n) {
        vector<int> v(A,A+n);
        //return canJump(v,0);
        //return canJump2(v);
        return canJump3(v);
    }
    
    //iterative
    bool canJump2(const vector<int>& v){
        vector<bool> reach(v.size(),false);
        reach[0]=true;
        for(int i = 0; i < v.size(); ++i){
            if(reach[i]){
                int len = v[i];
                for(int j = 1; j < len; ++j){
                    reach[i+j]=true;
                    if(i+j==v.size()-1)
                        return true;
                }
            }
        }
        
        return reach[v.size()-1];
    }
    
    //fast
    bool canJump3(const vector<int>& v){
        int start = 0, end = 0;
        while (start <= end) {
            end = max(end, start+v[start]);
            if (end >= v.size()-1) return true;
            start++;
        }
        return false;
    }
        
};



//-----------------------------

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:

    int jump(int A[], int n) {
        int start = 0, end = 0, step = 0;
        while (end < n-1) {
            int tmp = end;
            for (; start <= end; start++) tmp = max(tmp, start+A[start]);
            if (tmp <= end) return -1;
            end = tmp;
            step++;
        }

        return step;
    }
    
};

//-----------------------------

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/


class LRUCache{
public:

    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        auto it = _map[key];
        _list.push_front(*it);
        _list.erase(it);
        it = _list.begin();
        _map[key] = it;
        return it->second; 
    }

    void set(int key, int value) {
        auto it = _map.find(key);
        if (it != _map.end()) {
           _map.erase(key);
            _list.erase(it->second);
            _size--;
        }
        else if (_size == _capacity) {
            _map.erase(_list.back().first);
            _list.pop_back();
            _size--;
        }
        _list.push_front(make_pair(key, value));
        _map[key] = _list.begin();
        _size++;
    }

    list<pair<int, int> > _list;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
    int _size;
    int _capacity;
    
};

//-----------------------------

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:

    int largestRectangleArea(vector<int> &height) {
        
        if(height.size()==0)
            return 0;
            
        if(height.size()==1){
            return height[0];
        }
        
        vector<int> left(height.size(),0);
        stack<int> indexes;
        indexes.push(0);
        for(int i = 1 ; i < left.size(); ++i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                left[i] = i;
            }
            else{
                left[i] = i - indexes.top() - 1 ;
            }
            indexes.push(i);
        }
        
        vector<int> right(height.size(),0);
        indexes=stack<int>();
        indexes.push(height.size()-1);
        
        for(int i = right.size()-2; i >= 0 ; --i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                right[i] = right.size() - i - 1;
            }
            else{
                right[i] = indexes.top() - i - 1 ;
            }
            indexes.push(i);
        }
        
        int max = 0;
        for(int i = 0 ; i < height.size(); ++i){
            max = std::max(max, height[i]*(left[i]+1+right[i]) );
        }
        
        return max;
    }
    
};










//-----------------------------

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:

    int lengthOfLastWord(const char *s) {
        int N = strlen(s);
        if (N == 0) return 0;
        int end = N - 1;
        while (end >= 0 && s[end] == ' ') end--;
        if (end < 0) return 0;
        int start = end - 1;
        while (start >= 0 && s[start] != ' ') start--;
        return end - start;
    }
    
};

//-----------------------------

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/


class Solution {
public:
    static const string keypad[8];

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        letterCombinationsHelper(digits, 0, "", res);
        return res;
    }

    void letterCombinationsHelper(string& digits, int i, string str, vector<string> & res) {
        if (i == (int)digits.size()) {
            res.push_back(str);
            return;
        }
        int pos = digits[i] - '2';
        for (int j = 0; j < (int)keypad[pos].size(); j++) {
            letterCombinationsHelper(digits, i + 1, str + keypad[pos][j], res);
        }
    }
};

const string Solution::keypad[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };


//-----------------------------

/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode * fastNode = head, * slowNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) return true;
        }
        return false;
    }
};

//-----------------------------

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) break;
        }
        if (fastNode != slowNode) return NULL;

        fastNode = head;
        while (fastNode != slowNode) {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        return fastNode;
    }
};

//-----------------------------

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:

    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)
            return "";
            
        for(int i = 0 ; i < strs[0].size(); ++i ){
            char c =  strs[0][i];
            bool found = true;
            for(int j = 1; j < strs.size(); ++j){
                if( c != strs[j][i] ){
                    found = false;
                    break;
                }
            }
            if(!found){
                return strs[0].substr(0,i);
            }
        }
        
        return strs[0];
    }
    
};

//-----------------------------

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    //O(N)
    int longestConsecutive(vector<int> &num) {
	
        if(num.size()<=1)
            return num.size();
        
        unordered_set<int> hash;
        for(int i = 0 ; i < num.size(); ++i){
            hash.insert(num[i]);
        }
        
        int max = 0;
        
        while(!hash.empty()){
            int m = *(hash.begin());
            hash.erase(m);
            int l = m-1;
            int h = m+1;
            while(hash.count(l)>0){
                hash.erase(l);
                --l;
            }
            while(hash.count(h)>0){
                hash.erase(h);
                ++h;
            }
            
            max = std::max(max,h-l-1);
        }
        
        return max;
        
        
    }
};

//-----------------------------

/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:

    string longestPalindrome(string s) {
        return longestPalindrome2(s);
    }

    // take O(n^2) time, O(n^2) space
    string longestPalindrome1(string s) {
        if(s==""||s.size()==1)
            return s;
        
        int maxLen=1;
        int begin = 0;
        
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(),false) );
        
        for(int i = 0; i < s.size(); ++i){
            dp[i][i]=true;
            if(i<s.size()-1 && s[i]==s[i+1])
                dp[i][i+1]=true;
        }
        
        for(int len = 3; len <= s.size(); ++len){
            for(int i = 0; i + len <= s.size(); ++i){
                int j = i + len - 1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    begin=i;
                    maxLen=len;
                }
            }
        }
        
        return s.substr(begin,maxLen);
        
    }
    
    // take O(n^2) time, O(1) space
    string longestPalindrome2(string s) {
        int n = s.size();
        if (n == 0) return "";
        int maxi = 0;
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int start = i - j;
                int end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end])
                    start--, end++;
                start++, end--;
                int len = end - start + 1;
                if (len > maxl) maxi = start, maxl = len;
            }
        }
        return s.substr(maxi, maxl);
    }
    
    
    //O(N) (Manacher's Algorithm)
      string longestPalindrome_4(string s) {
        int N = s.size();
        int dp[2 * N + 1];
        int id = 0, mx = 0;
        for (int i = 0; i < 2 * N + 1; ++i)
        {
            int j = 2 * id - i;
            dp[i] = mx > i ? min(dp[j], mx - i) : 1;
            int left = i - dp[i], right = i + dp[i];
            for (; left >= 0 && right <= 2 * N; left--, right++)
            {
                if (left % 2 == 0 || s[left/2] == s[right/2]) // padding or char
                    dp[i]++;
                else
                    break;
            }
            if (i + dp[i] > mx)
            {
                id = i;
                mx = id + dp[id];
            }
        }

        int res = 0;
        for (int i = 1; i < 2 * N + 1; ++i)
            if (dp[i] > dp[res])
                res = i;

        return s.substr(res / 2 - (dp[res] - 1) / 2, dp[res] - 1);
    }
};


//-----------------------------

/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        //char,index 
        unordered_map<char,int> cache;
        
        int max = 0;
        int len = 0;
        for(int i = 0; i < s.size(); ++i){
            if(cache.count(s[i])==0){
                cache[s[i]]=i;
                ++len;
                max = std::max(max,len);
            }
            else{
                int preIndex = cache[s[i]];
                
                for(int j = preIndex; j >= i - len ; --j){
                    cache.erase(s[j]);
                }
                cache[s[i]]=i;
                len = cache.size();
                
            }
        }
        
        return max;
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
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution {
public:

    int maximalRectangle(vector<vector<char> > &matrix) {
        return maximalRectangle1(matrix);
    }
    
    
    //solution based on largestRectangleArea
    int maximalRectangle1(vector<vector<char> > &matrix) {
        if(matrix.size()==0||matrix[0].size()==0){
            return 0;
        }
        
        vector<vector<int> > area(matrix.size(),vector<int>(matrix[0].size(),0) );
        
        for(int j = 0; j<matrix[0].size();++j){
            for(int i = 0; i<matrix.size();++i){
                area[i][j]=(matrix[i][j] == '1');
            }
        }
        
        for(int j = 0; j<matrix[0].size();++j){
            for(int i = 1; i<matrix.size();++i){
                if(area[i][j]){
                    area[i][j] = area[i-1][j] + 1;
                }
            }
        }
        
        int max = 0;
        
        for(int i = 0; i<area.size();++i){
                
            max = std::max(max,largestRectangleArea(area[i]));
        }
        
        return max;
    }
    
    int largestRectangleArea(vector<int> &height) {
        
        if(height.size()==0)
            return 0;
            
        if(height.size()==1){
            return height[0];
        }
        
        vector<int> left(height.size(),0);
        stack<int> indexes;
        indexes.push(0);
        for(int i = 1 ; i < left.size(); ++i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                left[i] = i;
            }
            else{
                left[i] = i - indexes.top() - 1 ;
            }
            indexes.push(i);
        }
        
        vector<int> right(height.size(),0);
        indexes=stack<int>();
        indexes.push(height.size()-1);
        
        for(int i = right.size()-2; i >= 0 ; --i){
            while(indexes.empty()==false &&  height[ indexes.top() ] >= height[i] ){
                indexes.pop();
            }
            if(indexes.empty()){
                right[i] = right.size() - i - 1;
            }
            else{
                right[i] = indexes.top() - i - 1 ;
            }
            indexes.push(i);
        }
        
        int max = 0;
        for(int i = 0 ; i < height.size(); ++i){
            max = std::max(max, height[i]*(left[i]+1+right[i]) );
        }
        
        return max;
    }
    
};

//-----------------------------

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

    int maxDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left,right)+1;
        
    }
};

//-----------------------------

/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int t = m + n;
        if(!t)
            return 0.0;
            
        if(t%2)
            return (double)findkth(A,m,B,n,t/2+1);
        else
            return ( findkth(A,m,B,n,t/2+1) + findkth(A,m,B,n,t/2) ) / 2.0 ;
    }
    
    double findkth(int A[], int m, int B[], int n, int k){
        
        if(m>n)
            return findkth(B,n,A,m,k);
        if(m==0)
            return B[k-1];
        if(k==1)
            return min(A[0],B[0]);
            
        int a = min(k/2,m);
        int b = k - a;
        
        if(A[a-1]==B[b-1])
            return B[b-1];
        else if(A[a-1]<B[b-1])
            return findkth(A+a,m-a,B,n,k-a);
        else
            return findkth(A,m,B+b,n-b,k-b);
    }
 
    
};







//-----------------------------

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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

    struct MyComp{
        
        bool operator()(const Interval& i1, const Interval& i2){
            return i1.start<i2.start;
        }    
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
            
        sort(intervals.begin(),intervals.end(),MyComp());
        
        vector<Interval> v;
        
        Interval curI = intervals[0];
        
        int index = 1;
        
        while(index<intervals.size()){
            
            Interval newI = intervals[index];
            
            if(newI.start<=curI.end){
                curI.end = max(curI.end, newI.end);
            }
            else{
                v.push_back(curI);
                curI = newI;
            }
            
            ++index;
        }
        
        v.push_back(curI);
        
        return v;
    }
};














//-----------------------------

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    struct MyComp{
        bool operator()(ListNode* n1, ListNode* n2){
            return n1->val > n2->val;
        }  
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size()==1){
            return lists[0];
        }
        
        priority_queue<ListNode*, deque<ListNode*>, MyComp > heap;
        
        for(int i = 0 ; i < lists.size(); ++i ){
            if(lists[i]!=NULL)
                heap.push(lists[i]);
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(heap.empty()==false){
            ListNode* newNode = heap.top();
            heap.pop();
            if(newNode->next){
                heap.push(newNode->next);
            }
            
            if(!head){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        return head;
        
    }
};

//-----------------------------

/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }
        while (i >= 0) A[k--] = A[i--];
        while (j >= 0) A[k--] = B[j--];
        
    }
};

//-----------------------------

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Discuss
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        
        ListNode* head = NULL;
        if(l1->val<l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        head->next = mergeTwoLists(l1,l2);
        return head;
    }
};

//-----------------------------

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
 //leaf is not root itself
class Solution {
public:

    //BFS is better than DFS
    int minDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
            
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        int level = 1;
        
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            --size;
            
            //leaf
            if(n->left==NULL&&n->right==NULL){
                return level;
            }
            
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
            
            if(0==size){
                size = q.size();
                ++level;
            }
        }
            
    }
    
};

//-----------------------------

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int N = grid.size();
        if(!N)
            return 0;
        int M = grid[0].size();
        if(!M)
            return 0;
            
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(i==0&&j==0)
                    continue;
                grid[i][j] = min(i>0?grid[i-1][j]:INT_MAX , j>0?grid[i][j-1]:INT_MAX) + grid[i][j];
            }
        }
        
        return grid[N-1][M-1];
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
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative
*/

class Solution {
public:

    int ctoi(char c){
        return c-'0';
    }

    char itoc(int i){
        return i +'0';
    }
    
    string multiply(string num1, string num2) {
        
        if(num1=="0"||num2=="0")
            return "0";
        
        string ret(num1.size()+num2.size(),'0');
        
        for(int i = num1.size()-1; i>=0; --i){
            int a = ctoi(num1[i]);
            int j = num2.size()-1;
            int carry = 0;
            for(; j>=0; --j){
                int b = ctoi(num2[j]);
                int sum = a * b + carry + ctoi(ret[i+j+1]);
                ret[i+j+1] = itoc(sum % 10);
                carry = sum / 10;
            }
            if(carry)
                ret[i+j+1] = itoc(carry);
        }
        
        int k = 0;
        while(ret[k]=='0')
            ++k;
            
        ret=ret.substr(k);
        
        return ret;
    }
    
};

//-----------------------------

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/


class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col) {
        int N = board.size();
        int i = row, j = 0;
        while(j < col)
            if (board[i][j++] == 'Q') return false;
        i = row, j = col;
        while (i >=0 && j >= 0)
            if (board[i--][j--] == 'Q') return false;
        i = row, j = col;
        while (i < N && j >= 0)
            if (board[i++][j--] == 'Q') return false;
        return true;
    };

    void solveNQueensHelper(vector<string> &board, int col, vector<vector<string> > &result) {
        int N = board.size();
        if (col == N) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 'Q';
                solveNQueensHelper(board, col + 1, result);
                board[i][col] = '.';
            }
        }
    };

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        string row(n, '.');
        vector<string> board(n, row);
        solveNQueensHelper(board, 0, result);
        return result;
    }
    
};

//-----------------------------

/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    bool isSafe(int board[], int n, int row, int col) {
        for (int j = 0; j < col; j++)
            if (board[j] == row || abs(board[j] - row) == col - j)
                return false;
        return true;
    }

    void totalNQueensHelper(int board[], int n, int col, int &count) {
        if (col == n) count++;
        for (int row = 0; row < n; row++) {
            if (isSafe(board, n, row, col)) {
                board[col] = row;
                totalNQueensHelper(board, n, col+1, count);
            }
        }
    }

    int totalNQueens(int n) {
        int count = 0;
        int board[n];
        totalNQueensHelper(board, n, 0, count);
        return count;
    }
};

//-----------------------------

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:

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
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:

    bool isPalindrome(int x) {
        
        if(x<0)
            return false;
        
        if(x>=0&&x<=9)
            return true;
            
        int numDigits = (int)floor( log10(x) );
        
        while(x>=10){
            
            int most = x / pow(10,numDigits) ;
            int least = x % 10;
            if(most!=least)
                return false;
            x -= most * pow(10,numDigits);
            x /= 10;
            
            numDigits -= 2;
        }
        
        return true;
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
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *partition(ListNode *head, int x) {
        ListNode* frontHead = new ListNode(-1), *frontNode = frontHead;
        ListNode* backHead = new ListNode(-1), *backNode = backHead;
        while (head != NULL) {
            if (head->val < x) frontNode->next = head, frontNode = frontNode->next;
            else backNode->next = head, backNode = backNode->next;
            head = head->next;
        }
        backNode->next = NULL;
        frontNode->next = deleteNode(backHead);
        return deleteNode(frontHead);
    }

    ListNode * deleteNode(ListNode * curNode) {
        ListNode * toDel = curNode;
        curNode = curNode->next;
        delete toDel;
        return curNode;
    }
};

//-----------------------------

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
        vector<vector<int> > res;
        for (int r = 0; r < numRows; r++) res.push_back(vector<int>(r+1, 1));
        for (int r = 2; r < numRows; r++)
            for (int c = 1; c < r; c++)
                res[r][c] = res[r-1][c-1]+res[r-1][c];

        return res;
        
    }
};

//-----------------------------

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> row(rowIndex+1,1);
        for(int r = 2; r<=rowIndex; ++r){
            for(int c = r-1; c >= 1 ; --c){
                row[c] += row[c-1];
            }
        }
        
        return row;
    }
};

//-----------------------------

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

    bool hasPathSum(TreeNode *root, int sum, int preSum) {
        
        if(root==NULL)
            return false;
            
        if(root->left==NULL&&root->right==NULL){
            if(sum==preSum+root->val)
                return true;
            return false;
        }
        
        if( hasPathSum(root->left,sum,preSum+root->val) ||
            hasPathSum(root->right,sum,preSum+root->val))
            return true;
        
        return false;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {

        return hasPathSum(root,sum,0);
    }
};

//-----------------------------

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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

    vector<vector<int> > vv;
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        
        if(root==NULL)
            return vv;
            
        vector<int> path;
        pathSum(root,sum,path,0);
        return vv;
        
    }
    
    void pathSum(TreeNode *root, int sum, vector<int>& path, int preSum){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL&&root->right==NULL){
            if(sum==preSum+root->val){
                path.push_back(root->val);
                vv.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        path.push_back(root->val);
        pathSum(root->left,sum,path,preSum+root->val);
        pathSum(root->right,sum,path,preSum+root->val);
        path.pop_back();
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
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:

    vector<vector<int> > retVV;
    
    void permuteHepler(vector<int> &num ,vector<bool>& used, vector<int>& v) {
        if(v.size() == num.size()){
            retVV.push_back(v);
            return;
        }
        
        for(int i = 0; i < num.size(); ++i){
            if( ! used[i] ){
                used[i]=true;
                v.push_back(num[i]);
                permuteHepler(num,used,v);
                used[i]=false;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<int> v;
        vector<bool> used(num.size(),false);
        permuteHepler(num,used,v);
        return retVV;
    }
    
};

//-----------------------------

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    vector<vector<int> > retVV;
    
    void permuteHepler(vector<int> &num ,vector<bool>& used, vector<int>& v) {
        if(v.size() == num.size()){
            retVV.push_back(v);
            return;
        }
        
        for(int i = 0; i < num.size(); ++i){
            if( ! used[i] ){
                //previous same item must be used
                if( i>0 && (num[i-1]==num[i] && used[i-1]==false) )
                    continue;
                    
                used[i]=true;
                v.push_back(num[i]);
                permuteHepler(num,used,v);
                used[i]=false;
                v.pop_back(); 
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<int> v;
        vector<bool> used(num.size(),false);
        permuteHepler(num,used,v);
        return retVV;
    }
};

//-----------------------------

/*
Given a number represented as an array of digits, plus one to the number.
*/
class Solution {
public:

    vector<int> plusOne(vector<int> &digits) {
        
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (size_t i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) break;
        }
        if (carry != 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    
    }
    
};

//-----------------------------

/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //perfect binary tree
class Solution {
public:

    void connect(TreeLinkNode *root) {
        
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right;
        if (root->next == NULL)
            root->right->next = NULL;
        else
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        
    }
};



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void connect(TreeLinkNode *root) {
        
        if(root==NULL)
            return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        int count = 1;
        vector<TreeLinkNode*> v;
        
        while( !q.empty() ){
            
            TreeLinkNode* node = q.front();
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
                
            v.push_back(node);
            --count;
            
            if(count==0){
                count = q.size();
                v.push_back(NULL);
                for(int i = 0 ; i < v.size()-1; ++i){
                    v[i]->next=v[i+1];
                }
                v.clear();
            }
        
        }
    }
};

//-----------------------------

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //any binary tree
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(root==NULL)
            return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        int count = 1;
        vector<TreeLinkNode*> v;
        
        while( !q.empty() ){
            
            TreeLinkNode* node = q.front();
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
                
            v.push_back(node);
            --count;
            
            if(count==0){
                count = q.size();
                v.push_back(NULL);
                for(int i = 0 ; i < v.size()-1; ++i){
                    v[i]->next=v[i+1];
                }
                v.clear();
            }
        
        }
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
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}"
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

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    TreeNode* preNode = NULL;
    
    void recoverTree(TreeNode *root) {
        if(!root||(!root->left&&!root->right))
            return;
        inorder(root);
        swap(first->val,second->val);
    }
    
    //inorder traversal find first and second
    void inorder(TreeNode *root) {
        
        if(!root)
            return;
        
        inorder(root->left);
        
        if(preNode&&root->val<preNode->val){
            if(!first){
                first = preNode;
            }
            second = root;
        }
        
        preNode = root;
        
        inorder(root->right);
    }
    
    
};
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
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:

    int removeDuplicates(int A[], int n) {
        if(n<=1)
            return n;
        
        int curLen = 1;
        for(int i = 1; i < n ; ++i){
            if( A[i]!=A[i-1]){
                A[curLen] = A[i];
                ++curLen;
            }
        }
        
        return curLen;
    }
};

//-----------------------------

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

//duplicates are allowed at most twice
class Solution {
public:

    int removeDuplicates(int A[], int n) {
        
        int curLen = 0;

        int b = 0;
        int e = 1;
        
        while(b<n){
            
            while(e<n&&A[e]==A[b])
                ++e;
                
            int num = min(2,e-b);
            while(num-- > 0 )
                A[curLen++] = A[b];
                
            b = e;
            ++e;
        }
        
        return curLen;
    }
    
};

//-----------------------------

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates1(head);
    }
    //recursive
    ListNode *deleteDuplicates2(ListNode *head) {
        if (!head || !(head->next) ) return head;
        if ( head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        ListNode* next = head->next;
        delete head;
        return deleteDuplicates(next);
    }
    //iterative
    ListNode *deleteDuplicates1(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
            return head;
            
        ListNode* tail = head;
        int tailVal = tail->val;
        ListNode* cur = head->next;
        
        while(cur){
            if(cur->val!=tailVal){
                tail->next = cur;
                tail=tail->next;
                tailVal = tail->val;
                cur=cur->next;
            }else{
                ListNode* n = cur;
                cur=cur->next;
                delete n;
            }
        }
        
        tail->next = NULL;
        
        return head;
    }
    
};

//-----------------------------

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *deleteDuplicates(ListNode *head) {
        
        if(head==NULL)
            return NULL;

        map<int,int> cache;
        
        ListNode* cur = head;
        while(cur){
            cache[cur->val]++;
            cur=cur->next;
        }
        
        for(map<int,int>::iterator iter = cache.begin() ; iter != cache.end(); ){
            if(iter->second>1){
                cache.erase(iter++);
            }
            else{
                ++iter;
            }
        }
        
        ListNode* h = NULL;
        ListNode* t = NULL;
        for(map<int,int>::iterator iter = cache.begin() ; iter != cache.end(); ++iter){
            ListNode* n = new ListNode(iter->first);
            if(!h){
                h = n;
                t = n;
            }
            else{
                t->next = n;
                t = n;
            }
        }
        
        return h;
    }
    
};

//O(1) space
//iterative
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next)
        {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = node->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
}
*/

//recursive
/*
  ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next) ) return head;
        
        if ( head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        int v = head->val;
        ListNode* next = head;
        while(next&&next->val==v){
            ListNode* n = next;
            next = next->next;
            delete n;
        }
        
        return deleteDuplicates(next);
        
  }
  */

//-----------------------------

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
class Solution {
public:

    int removeElement(int A[], int n, int elem) {
        int newLen = 0;
        for(int i = 0 ; i < n; ++i){
            if(A[i]!=elem){
                swap(A[newLen++],A[i]);
            }
        }
        return newLen;
    }
    
};

//-----------------------------

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if (NULL == head || n <= 0) return head;
        ListNode *fastNode = head, *slowNode = head;
        while (fastNode != NULL && n > 0) fastNode = fastNode->next, n--;
        if (fastNode == NULL) {
            if (n == 0) {
                head = head->next;
                delete slowNode;
            }
            return head;
        }
        while (fastNode->next != NULL) fastNode = fastNode->next, slowNode = slowNode->next;
        ListNode* nextNode = slowNode->next;
        slowNode->next = nextNode->next;
        delete nextNode;
        return head;
    }
    
};




//-----------------------------

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(!head||!(head->next)){
            return head;
        }
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
        
    }
    
    ListNode* interleave(ListNode* head, ListNode* head2){
        if(!head){
            return head2;
        }
        if(!head2){
            return head;
        }
        
        ListNode* newHead = head;
        head = head->next;
        newHead->next = interleave(head2,head);
        
        return newHead;
    }
    
    void reorderList(ListNode *head) {
        
        if(!head||!(head->next))
            return;
            
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow ->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        //reverse head2;
        head2 = reverse(head2);
        
        //interleave head head2
        head=interleave(head,head2);
        
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
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
    	bool neg = false;
        if(x==0)
        	return 0;
        if(x<0){
        	neg = true;
    		x *= -1;
    	}

    	int y = 0;
    	while(x){
    		y *= 10;
    		y += x%10;
    		x /= 10;
    	}

    	return neg?-y:y;
    }
};

//-----------------------------

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head){
        
        if(!head||!(head->next))
            return head;
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
		//assume n and m are within the range and n >= m
        if(m==n)
            return head;
            
        //dummy head make life easier for case that m==1
        ListNode dummy(0);
        ListNode* newHead = &dummy;
        newHead->next = head;
        
        ListNode* preM = newHead;
        ListNode* nodeN = newHead;
        
        int index = 1 ;
        while(index<=n){
            if(index<m){
                preM = preM->next;
            }
            nodeN = nodeN->next;
            ++index;
        }

        ListNode* nodeM = preM->next;
        preM->next = NULL;
        
        ListNode* postN = nodeN->next;
        nodeN->next = NULL;
  
        preM->next = reverse(nodeM);
        nodeM->next = postN;

        return newHead->next;
    }
    
};

//-----------------------------

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head){
        
        if(!head||!(head->next))
            return head;
        
        ListNode* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        
        ListNode* cur = head;
        ListNode* pre = head;
        int i = 0;
        
        while( cur && i < k){
            if(i<k-1)
                pre=pre->next;
            cur = cur->next;
            ++i;
        }

        //less than k elements
        if(i<k){
            return head;
        }
    
        pre->next=NULL;
        ListNode* node = reverseKGroup(cur,k);
        
        ListNode* newHead = reverse(head);
        head->next=node;
        
        assert(pre==newHead);
        
        return pre;
    }
    
};

//-----------------------------

/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/

class Solution {
public:
    map<char, int> dict;
    int romanToInt(string s) {
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        int res = 0;
        size_t i = 0;
        while (i < s.size() - 1) {
            if (dict[s[i]] < dict[s[i+1]]) res -= dict[s[i]];
            else res += dict[s[i]];
            i++;
        }
        res += dict[s[i]];
        return res;
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
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *rotateRight(ListNode *head, int k) {
        
        if(!head){
            return head;
        }
        
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur -> next;
            ++len;
        }
        
        k = k%len;
        if(k==0){
            return head;
        }
        
        k = len - k;
        
        ListNode* pre = head;
        cur = head;
        
        int i = 0;
        while(i!=k){
            if(i<k-1)
                pre = pre -> next;
            cur = cur ->next;
            ++i;
        }
        pre->next = NULL;
        
        ListNode* newHead = cur;
        ListNode* tail = cur; 
        while(tail->next){
            tail = tail->next;
        }
        
        tail->next = head;
        
        return newHead;
        
    }
    
};

//-----------------------------

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==q)
            return true;
        
        if( (p==NULL) ^ (q==NULL) )
            return false;
        
        if(p->val!=q->val)
            return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//-----------------------------

/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

class Solution {
public:

    bool isScramble(string s1, string s2) {
        
        if(s1==s2)
            return true;
            
        if(s1.size()!=s2.size())
            return false;
        
        //check chars
        char arr[256]={0};
        for(int i = 0; i < s1.size(); ++i){
            arr[s1[i]]++;
            arr[s2[i]]--;
        }
        for(int i = 0; i < 256; ++i){
            if(arr[i]!=0)
                return false;
        }
        
        for(int i = 1; i < s1.size(); ++i){
            
            string leftS1 = s1.substr(0,i);
            string rightS1 = s1.substr(i);
            
            string leftS2 = s2.substr(0,i);
            string rightS2 = s2.substr(i);
            
            string leftS2reverse = s2.substr(s1.size()-i);
            string rightS2reverse = s2.substr(0,s1.size()-i);
            
            if(isScramble(leftS1,leftS2)&&isScramble(rightS1,rightS2)){
                return true;
            }
            if(isScramble(leftS1,leftS2reverse)&&isScramble(rightS1,rightS2reverse)){
                return true;
            }
        }
        
        return false;
    }
	
	
	// solution 1: dp. 3-dimensional dp
	/*
	'dp[k][i][j] == true' means string s1(start from i, length k) is a scrambled string of 
              string s2(start from j, length k).
	*/
    bool isScramble_1(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int N = s1.size();
        bool dp[N+1][N][N];
        for (int k = 1; k <= N; ++k)
            for (int i = 0; i <= N-k; ++i)
                for (int j = 0; j <= N-k; ++j)
                {
                    dp[k][i][j] = false;
                    if (k == 1) 
                        dp[1][i][j] = (s1[i] == s2[j]);
                    for (int p = 1; p < k && !dp[k][i][j]; ++p)
                        if (dp[p][i][j] && dp[k-p][i+p][j+p] || dp[p][i][j+k-p] && dp[k-p][i+p][j])
                            dp[k][i][j] = true;
                }
        return dp[N][0][0];
    }
    
};

//-----------------------------

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        searchMatrix1(matrix,target);
    }
    
    //O(lgN)
    bool searchMatrix1(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();
        int l = 0, u = M*N-1;
        while (l <= u) {
            int m = l+(u-l)/2;
            if (matrix[m/N][m%N] == target) return true;
            if (matrix[m/N][m%N] < target) l = m+1;
            else u = m-1;
        }
        return false;
    }
};

//-----------------------------

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:

    vector<int> searchRange(int A[], int n, int target) {
        int l = lower_bound(A, n, target);
        int u = upper_bound(A, n, target);
        vector<int> res(2, -1);
        if(l!=u){
            res[0] = l;
            res[1] = u-1;
        }
        return res;
    }

    //[ )
    int lower_bound(int A[], int n, int target) {
        int l = 0, u = n;
        while (l < u) {
            int m = l+(u-l)/2;
            if (A[m] < target) l = m+1;
            else u = m;
        }
        return l;
    }

    //[ )
    int upper_bound(int A[], int n, int target) {
        int l = 0, u = n;
        while (l < u) {
            int m = l+(u-l)/2;
            if (A[m] <= target) l = m+1;
            else u = m;
        }
        return l;
    }
    
};




//-----------------------------

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:

    int search(int A[], int n, int target) {
        
        int b = 0, e = n -1;
        
        while(b<=e){
            int m = b + (e-b)/2;
            if(A[m]==target){
                return m;
            }else if(A[m]>=A[b]){
                
                if(A[m]>=target&&target>=A[b]){
                    e = m - 1;
                }
                else{
                    b = m + 1;
                }
            }
            else{
                
                if(A[e]>=target&&target>=A[m]){
                    b = m + 1;
                }
                else{
                    e = m - 1;
                }
            }
        }
        
        return -1;
    }
    

};

//-----------------------------

/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (A[i] == target) return true;
        }
        return false;
    }
};

//-----------------------------

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
    
public:

    int lower_bound(const vector<int>& v, int target){
        int l = 0;
        int h = v.size();
        while(l<h){
            int m = l + (h-l)/2;
            if(v[m]==target){
                return m;
            }
            else if(v[m]>target){
                h = m ;
            }
            else{
                l = m + 1;
            }
        }
        
        return h;
    }
    
    int searchInsert(int A[], int n, int target) {
        vector<int> v(A,A+n);
        return lower_bound(v,target);
    }
    
};

//-----------------------------

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:

    void setZeroes(vector<vector<int> > &matrix) {
        
        if(matrix.size()==0||matrix[0].size()==0)
            return ;
        
        //constant memory
        setZeroes2(matrix);
        return;
        
        vector<bool> rows(matrix.size(),false);
        vector<bool> cols(matrix[0].size(),false);
        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0 ;j  < matrix[i].size(); ++j){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    cols[j]=true;
                }
            }
        }
        
        //set rows
        for(int i = 0; i < rows.size(); ++i){
            if(rows[i]){
                for(int j = 0; j < matrix[i].size(); ++j){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //set cols
        for(int j = 0; j < cols.size(); ++j){
            if(cols[j]){
                for(int i = 0; i < matrix.size(); ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
    
    
    //first row and first column are reused
    void setZeroes2(vector<vector<int> > &matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int fr = 1;
        for (int j = 0; j < N; j++) {
            if (matrix[0][j] == 0) {
                fr = 0;
                break;
            }
        }
        int fc = 1;
        for (int i = 0; i < M; i++) {
            if (matrix[i][0] == 0) {
                fc = 0;
                break;
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (fr == 0) {
            for (int j = 0; j < N; j++) matrix[0][j] = 0;
        }

        if (fc == 0) {
            for (int i = 0; i < M; i++) matrix[i][0] = 0;
        }
    }
    
};

//-----------------------------

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

//-----------------------------

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0 ;
        for(int i = 0; i<n ;++i){
            one ^= A[i];
        }
        return one;
    }
    
};

//-----------------------------

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:

    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1<<i;
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (A[j]&mask) sum++;
            if (sum%3) res |= mask;
        }
        return res;
    }
    
};

//-----------------------------

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

class Solution {
public:

    void sortColors(int A[], int n) {
        if(n<=1)
            return;
            
        int cur = 0;
        int end0 = 0;
        int begin2 = n;
        
        while(cur<begin2){
            if(A[cur]==1){
                ++cur;
            }
            else if(A[cur]==0){
                swap(A[end0++],A[cur++]);
            }
            else{
                swap(A[--begin2],A[cur]);
            }
        }
    }
    
};

//-----------------------------

/*
Sort a linked list in O(n log n) time using constant space complexity.
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergetSort(head);    
    }

    ListNode *mergetSort(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * frontHead = head, * backHead = split(head);
        frontHead = mergetSort(frontHead);
        backHead = mergetSort(backHead);
        return merge(frontHead, backHead);
    }

    ListNode * split(ListNode * head) {
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode->next != NULL && fastNode->next->next != NULL) fastNode = fastNode->next->next, slowNode = slowNode->next;
        head = slowNode->next;
        slowNode->next = NULL;
        return head;
    }

    ListNode * merge(ListNode * frontHead, ListNode * backHead) {
        ListNode * head = new ListNode(-1), * curNode = head;
        while (frontHead != NULL || backHead != NULL) {
            if (backHead == NULL || (frontHead != NULL && frontHead->val <= backHead->val)) curNode->next = frontHead, frontHead = frontHead->next;
            else curNode->next = backHead, backHead = backHead->next;
            curNode = curNode->next;
        }
        return deleteNode(head);
    }

    ListNode * deleteNode(ListNode * curNode) {
        ListNode * toDel = curNode;
        curNode = curNode->next;
        delete toDel;
        return curNode;
    }
};

//-----------------------------

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int> v;
        if(matrix.size()==0||matrix[0].size()==0)
            return v;
            
        vector<pair<int,int> > dirs;
        dirs.push_back(pair<int,int>(0,1));
        dirs.push_back(pair<int,int>(1,0));
        dirs.push_back(pair<int,int>(0,-1));
        dirs.push_back(pair<int,int>(-1,0));
        
        int N = matrix.size() * matrix[0].size();
        int i = 0; 
        int j = 0;
        int cur = 0;
        
        for(int k = 0; k < N; ++k){
            
            v.push_back(matrix[i][j]);
            matrix[i][j] = 0; //mark the border
            
            pair<int,int> curDir = dirs[cur];
            int nextI = i + curDir.first;
            int nextJ = j + curDir.second;
            
            if( nextI>=matrix.size()||nextI<0 || 
                nextJ >=matrix[0].size() || nextJ < 0 || 
                matrix[nextI][nextJ]==0){
                   cur = (cur+1)%dirs.size();
                   pair<int,int> curDir = dirs[cur];
                   nextI = i + curDir.first;
                   nextJ = j + curDir.second;
            }
            
            i = nextI;
            j = nextJ;
            
        }
        
        return v;
    }
    
};

//-----------------------------

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:

    vector<vector<int> > generateMatrix(int n) {
        
        if(n<=0)
            return vector<vector<int> >();
        
        vector<vector<int> > matrix(n,vector<int>(n,0));
        
        vector<pair<int,int> > dirs;
        dirs.push_back(pair<int,int>(0,1));
        dirs.push_back(pair<int,int>(1,0));
        dirs.push_back(pair<int,int>(0,-1));
        dirs.push_back(pair<int,int>(-1,0));
        
        int i = 0; 
        int j = 0;
        int cur = 0;
        
        for(int k = 1; k <= n*n; ++k){
            
            matrix[i][j] = k; //set value and mark the border
            
            pair<int,int> curDir = dirs[cur];
            int nextI = i + curDir.first;
            int nextJ = j + curDir.second;
            
            if( nextI>=matrix.size()||nextI<0 || 
                nextJ >=matrix[0].size() || nextJ < 0 || 
                matrix[nextI][nextJ]!=0){
                   cur = (cur+1)%dirs.size();
                   pair<int,int> curDir = dirs[cur];
                   nextI = i + curDir.first;
                   nextJ = j + curDir.second;
            }
            
            i = nextI;
            j = nextJ;
            
        }
        
        return matrix;
    }
    
};

//-----------------------------

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:

   int sqrt(int x) {
        if(x < 2) return x;
        long long l = 1;
        long long u = 1 + (x / 2);
        while(l + 1 < u) {
            long long m = l + (u - l) / 2;
            long long p = m * m;
            if(p > x)
                u = m;
            else if(p < x)
                l = m;
            else
                return m;
        }
        return (int)l;
    }
    
};

//how about double sqrt(double x)

//-----------------------------

/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

class Solution {
public:
    char * strStr(char * haystack, char * needle) {
        if (!haystack || !needle) return haystack;
        int n = strlen(haystack);
        int m = strlen(needle);
        if (n < m) return NULL;
        if (m == 0) return haystack;
        return strStr3(haystack, n, needle, m);
    }

    // brute force, takes O(n*m) time
    char *strStr1(char *haystack, int n, char *needle, int m) {
        int i = 0;
        while (i < n-m+1) {
            int j = 0;
            while (j < m && haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == m) return haystack+(i-j);
            i = i-j+1;
        }
        return NULL;
    }
    
    /*
    // Rabin-Karp (RK), takes O(n+m) times, but O(n*m) worst case
    char * strStr2(char * haystack, int n, char * needle, int m) {
        int hn = 0;
        for (int i = 0; i < m; i++) hn = mod(hn*B+needle[i], M);

        int hh = 0;
        for (int i = 0; i < m; i++) hh = mod(hh*B+haystack[i], M);

        if (hh == hn) return haystack;

        int E = 1;
        for (int i = 1; i < m; i++) E = mod(E*B, M);

        for (int i = m; i < n; i++) {
            hh = mod(hh-mod(haystack[i-m]*E, M), M);
            hh = mod(hh*B+haystack[i], M);

            if (hh == hn) {
                int j = 0;
                while (j < m && haystack[i+j] == needle[j]) j++;
                return haystack+i-m+1;
            }
        }
        return NULL;
    }

    int mod(int a, int b) {
        return (a%b+b)%b;
    }
    */
    
    // Knuth-Morris-Pratt Algorithm (KMP), takes O(n+m)
    char * strStr3(char * haystack, int n, char * needle, int m) {
        vector<int> fs = build(needle, m);
        int i = 0, j = 0;
        int step = 10000;
        while (j < n) {
            if (j == n) break;
            if (haystack[j] == needle[i]) {
                i++;
                j++;
                if (i == m) return haystack+j-m;
            }
            else if (i > 0) i = fs[i];
            else j++;
            step--;
            if (step == 0) break;
        }
        return NULL;
    }

    vector<int> build(char * needle, int m) {
        vector<int> fs(m+1, 0);
        for (int i = 2; i <= m; i++) {
            int j = fs[i-1];
            while (true) {
                if (needle[j] == needle[i-1]) {
                    fs[i] = j+1;
                    break;
                }

                if (j == 0) {
                    fs[i] = 0;
                    break;
                }

                j = fs[j];
            }
        }

        return fs;
    }
};

//-----------------------------

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

};

//-----------------------------

/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void subsets(vector<int> &S, int index, vector<int>& v, 
    			 vector<vector<int> >& vv, vector<bool>& used) {

		vv.push_back(v);

		if(index < S.size()){
			for(int i = index; i < S.size(); ++i){
				//make sure previous same one must be used
				if(i>0&&S[i-1]==S[i]&&used[i-1]==false)
					continue;

				v.push_back(S[i]);
				used[i]=true;
				subsets(S,i+1,v,vv,used);
				v.pop_back();
				used[i]=false;
			}
		}
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > vv;
        vector<int> v;
        vector<bool> used(S.size(),false);
        sort(S.begin(),S.end());
        subsets(S,0,v,vv,used);
        return vv;
    }
};

//-----------------------------

/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:

    vector<int> findSubstring(string S, vector<string> &L) {
        
        vector<int> v;
        
        if(S==""||L.size()==0||L[0].size()==0)
            return v;
        
        int len = L[0].size();
        
        if(S.size()<len*L.size())
            return v;
        
        unordered_map<string,int> needs;
        for(int i = 0 ; i < L.size(); ++i){
            needs[L[i]]++;
        }
        
        for(int i = 0; i <= S.size()-len*L.size(); ++i){
            unordered_map<string,int> founds;
            int j = 0;
            for(; j < L.size(); ++j){
                string str = S.substr(i+j*len,len);
                if(needs.count(str)==0)
                    break;
                founds[str]++;
                if(founds[str]>needs[str])
                    break;
            }
            
            if(j==L.size()){
                    v.push_back(i);
            }
        }    
        
        return v;
    }
    
};

//-----------------------------

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char> > &board, int row, int col) {
        bool res = getNextEmpty(board, row, col);
        if (!res) return true;
        vector<char> possible;
        getPossibleValues(board, possible, row, col);
        if (possible.size() == 0) return false;
        for (size_t i = 0; i < possible.size(); i++) {
            board[row][col] = possible[i];
            if (solve(board, row, col)) return true;
            board[row][col] = '.';
        }
        return false;
    }

    bool getNextEmpty(vector<vector<char> > &board, int &row, int &col) {
        while (row <= 8 && col <= 8) {
            if (board[row][col] == '.') return true;
            row = (col == 8) ? row + 1 : row;
            col = (col == 8) ? 0 : col + 1;
        }
        return false;
    }

    void getPossibleValues(vector<vector<char> > &board, vector<char> &possible, int row, int col) {
        bool s[9] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[row][i] != '.') s[board[row][i]-'1'] = true;
            if (board[i][col] != '.') s[board[i][col]-'1'] = true;
            char c = board[row/3*3+i/3][col/3*3+i%3];
            if (c!='.') s[c-'1'] = true;
        }
        for (int i = 0; i < 9; i++) {
            if (!s[i]) possible.push_back('1'+i);
        }
    }
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
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:

    void solve(vector<vector<char>> &board) {
        
        if(board.size()<3||board[0].size()<3){
            return;
        }
        
        solve2(board);
    }
    
     void solve2(vector<vector<char>> &board)
    {
        if (board.empty()) return;
        int M = board.size();
        int N = board[0].size();

        for (int i = 0; i < M; i++)
        {
            if (board[i][0] == 'O') bfs(board, M, N, i, 0);
            if (board[i][N-1] == 'O') bfs(board, M, N, i, N-1);
        }

        for (int j = 1; j < N-1; j++)
        {
            if (board[0][j] == 'O') bfs(board, M, N, 0, j);
            if (board[M-1][j] == 'O') bfs(board, M, N, M-1, j);
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'D') board[i][j] = 'O';
    }

    void bfs(vector<vector<char>> &board, int M, int N, int i, int j)
    {
        queue<pair<int, int>> queue;
        board[i][j] = 'D';
        queue.push(make_pair(i, j));
        
        while (!queue.empty())
        {
            i = queue.front().first;
            j = queue.front().second;
            queue.pop();
            if (i > 1 && board[i-1][j] == 'O')
            {
                board[i-1][j] = 'D';
                queue.push(make_pair(i-1, j));
            }
            if (i < M-1 && board[i+1][j] == 'O')
            {
                board[i+1][j] = 'D';
                queue.push(make_pair(i+1, j));
            }
            if (j > 1 && board[i][j-1] == 'O')
            {
                board[i][j-1] = 'D';
                queue.push(make_pair(i, j-1));
            }
            if (j < N-1 && board[i][j+1] == 'O')
            {
                board[i][j+1] = 'D';
                queue.push(make_pair(i, j+1));
            }
        }
    }
	
	/*
	    void solve(vector<vector<char>> &board) {
        
        if(board.size()<3||board[0].size()<3)
            return;
        
        for(int i = 0 ; i < board[0].size(); ++i){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[board.size()-1][i]=='O') dfs(board,board.size()-1,i);    
        }
        
        for(int i = 0 ; i < board.size(); ++i){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);    
        }
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j]=='B') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        return;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j){
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!='O')
            return;
        
        board[i][j]='B'; //mark it as border
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
	*/
};

//-----------------------------

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode* reHead = swapPairs(head->next->next);
        
        ListNode* next =  head->next;
        
        head->next = reHead;
        
        next->next = head;
        
        head = next;
        
        return head;
    }
};

//-----------------------------

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

    //recursive
    bool isSymmetric(TreeNode * l, TreeNode * r) {
                
        if( (l==NULL) ^ (r==NULL) )
            return false;
            
        if(!l)
            return true;
        
        if(l->val!=r->val)
            return false;
        
        return isSymmetric(l->left,r->right) && isSymmetric(l->right,r->left);
    }


    bool isSymmetric(TreeNode *root) {
        
        if(root==NULL)
            return true;
            
        //return isSymmetric(root->left,root->right);
        return isSymmetric2(root);
     
    }
    
    //iterative
    bool isSymmetric2(TreeNode *root){
        
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        vector<int> v;
        
        while(!q.empty()){
            
            TreeNode* n = q.front();
            q.pop();
            --size;
            
            if(n!=NULL){
                v.push_back(n->val);
                q.push( n->left?n->left: NULL);
                q.push( n->right?n->right: NULL);
            }
            else{
                v.push_back('#');
            }
            
            if(size==0){
                
                size=q.size();
                
                for(int i = 0 , j = v.size()-1; i<j ; ++i,--j){
                    if(v[i]!=v[j])
                        return false;
                }
                v.clear();
            }
        }
        
        return true;
    }
    
};









//-----------------------------

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

//-----------------------------

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

class Solution {
public:

    int trap(int A[], int n) {
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int max = 0;
        for(int i = 0; i < n; ++i){
            max = std::max(max,A[i]);
            left[i]=max;
        }
        
        max = 0;
        for(int i = n-1; i >- 0; --i){
            max = std::max(max,A[i]);
            right[i]=max;
        }
        
        int water = 0 ;
        
        for(int i = 1; i < n-1; ++i){
            water += min(left[i],right[i]) - A[i];
        }
     
        return water;   
    }
};

//-----------------------------

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:

    int minimumTotal(vector<vector<int> > &triangle) {
        
        int row = triangle.size();
        
        vector<int> v(row+1,0);
        
        for(int i = row-1; i>=0; --i){
            for(int j = 0 ; j < row; ++j){
                v[j] = triangle[i][j] + min(v[j],v[j+1]);
            }
        }
        
        return v[0];
    }
    
};

//-----------------------------

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:

    unordered_map<int,int> cache;
    
    int numTrees(int n) {
        
        if(n<=1)
            return 1;
        if(cache.count(n))
            return cache[n];
            
        int num = 0;
        for(int i = 0; i<n; ++i){
            int left = i;
            int right = n - i - 1;
            num += numTrees(i)*numTrees(right);
        }
        
        cache[n] = num;
        
        return num;

    }
};

//-----------------------------

/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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

    //unordered_map<pair<int,int>, vector<TreeNode*> > cache;
    
    vector<TreeNode *> generateTrees(int b, int e){
        
        vector<TreeNode *> v;
        
        if(b>e){
            v.push_back(NULL);
            return v;
        }
            
        if(b==e){
            TreeNode* n = new TreeNode(b);
            v.push_back(n);
            return v;
        }
    
        for(int m = b; m <= e; ++m){
            vector<TreeNode *> left = generateTrees(b,m-1);
            vector<TreeNode *> right = generateTrees(m+1,e);
            
            for(int i = 0; i< left.size(); ++i){
                for(int j =0 ;j<right.size();++j){
                    TreeNode* n = new TreeNode(m);
                    n->left = left[i];
                    n->right = right[j];
                    v.push_back(n);
                }
            }
        }
        
        return v;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        
         return generateTrees(1,n);
    }
    
};

//-----------------------------

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:

    int uniquePaths(int m, int n) {
        
        if( m<=0 || n <=0 )
            return 0;
        
        vector<vector<int> > dp(m, vector<int>(n,0));
        
        dp[0][0]=1;
        
        for(int i = 0 ; i < m; ++i){
            for(int j = 0 ; j < n; ++j){
                dp[i][j] +=  (i==0?0:dp[i-1][j]) + (j==0?0:dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1];
        
    }
};

//-----------------------------

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0)
            return 0;
        
        if(obstacleGrid[0][0]||obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1])
            return 0;
           
        vector<vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(),0) ); 
        
        dp[0][0]=1;
        
        for(int i = 0; i < dp.size(); ++i ){
            for(int j = 0; j < dp[0].size(); ++j){
                //not obstacle
                if(obstacleGrid[i][j]==0){
                    dp[i][j] += (i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
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
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};

//-----------------------------

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:

    unordered_map<char,char> hash;
    
    bool isValid(string s) {
        hash['(']=')';
        hash['{']='}';
        hash['[']=']';
        
        if(s=="")
            return true;
            
        if(s.size()%2!=0)
            return false;
            
        stack<char> stack;
        int i = 0;
        
        while(i<s.size()){
            char c = s[i];
            if( c=='(' || c=='{' || c=='[' ){
                stack.push(c);
            }else if(c==')' || c=='}' || c==']'){
                if(stack.empty()==true)
                    return false;
                char cc = stack.top();
                stack.pop();
                if(hash[cc] != c)
                    return false;
            }
            else{
                return false;
            }
            ++i;
        }
        
        if(stack.empty())
            return true;
        return false;
    }
};

//-----------------------------

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
http://sudoku.com.au/TheRules.aspx
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int M = board.size();
        if (M == 0) return false;
        int N = board[0].size();
        if (N == 0) return false;
        if (M % 3 != 0 || N % 3 != 0) return false;

        bool visited[10];
        // check row
        for (int i = 0; i < M; i++) {
            memset(visited, false, sizeof(bool) * 10);
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (visited[k]) return false;
                    visited[k] = true;
                }
            }
        }

        // check coloumn
        for (int j = 0; j < N; j++) {
            memset(visited, false, sizeof(bool) * 10);
            for (int i = 0; i < M; i++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (visited[k]) return false;
                    visited[k] = true;
                }
            }
        }

        // check block
        for (int i = 0; i < M; i++) {
            memset(visited, false, sizeof(bool) * 10);
            for (int j = 0; j < N; j++) {
                int r = i/3*3 + j/3;
                int c = i%3*3 + j%3;
                if (board[r][c] != '.') {
                    int k = board[r][c] - '0';
                    if (visited[k]) return false;
                    visited[k] = true;
                }
            }
        }
        return true;
    }
};

//-----------------------------

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

    int pre = INT_MIN;
    
    bool isValidBST(TreeNode *root) {
        
        if(root==NULL){
            return true;
        }    
        
        if( !isValidBST(root->left) )
            return false;
        
        if(root->val <= pre)
            return false;
        
        pre = root->val;
        
        return isValidBST(root->right);
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

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:

    typedef vector<vector<char> > VECTOR2D;
    
    bool exist(VECTOR2D &board, string word) {
        int N = board.size(), M = board[0].size();
        VECTOR2D avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, avail))
                    return true;
        return false;
    }

    bool existRe(const VECTOR2D &board, const string &word, int deep, int i, int j, VECTOR2D &avail)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || avail[i][j] == 'x') return false;
        
        avail[i][j] = 'x';
        if (existRe(board, word, deep + 1, i-1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i+1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i, j-1, avail)) return true;
        if (existRe(board, word, deep + 1, i, j+1, avail)) return true;
        avail[i][j] = 'o';
        
        return false;
    }
  
    
};

//-----------------------------

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
*/
class Solution {
public:
    string convert(string s, int nRows)
    {
        if (nRows < 2) return s;
        int N = s.size();
        int L = 2 * (nRows - 1); // provide gap
        string res;
        res.clear();
        
        for (int i = 0; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        for (int i = 1; i < nRows - 1; i++)
        {
            for (int j = i; j < N; j += L)
            {
                int l = L-2*i; //small gap
                res.push_back(s[j]);
                int k = j+l;
                if (k < N) res.push_back(s[k]);
            }
        }
        for (int i = nRows - 1; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        
        return res;
    }
};

//-----------------------------

