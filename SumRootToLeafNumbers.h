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
class Solution {
public:

    void sumNumbersHelper(TreeNode *root, vector<int>& path, int& total) {
        
        path.push_back(root->val);
        
        if(root->left==NULL&&root->right==NULL){
            if(path.size()!=0){
                int sum = 0;
                for(int i =0 ;i<path.size();++i){
                    sum *= 10;
                    sum += path[i];
                }
                total += sum;
            }
            
            path.pop_back();
            return;
        }
        
        if(root->left)
            sumNumbersHelper(root->left,path,total); 
        if(root->right)
            sumNumbersHelper(root->right,path,total);
            
        path.pop_back();
    }
    
    int sumNumbers(TreeNode *root) {
        
        if(root==NULL)
            return 0;
        
        vector<int> path;
        int total = 0;
        sumNumbersHelper(root,path,total);
        
        return total;
    }
};

/*
class Solution {
public:

    int ans;
    void dfs(int cnt, TreeNode *rt) {
        cnt = 10 *cnt + rt->val;
        if (rt->left == NULL && rt->right == NULL) {
            ans += cnt;
            return;
        }
        if (rt->left != NULL)
            dfs (cnt, rt->left);
        if (rt->right != NULL)
            dfs (cnt, rt->right);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return 0;
        ans = 0;
        dfs(0, root);
        return ans;
    }
};
*/