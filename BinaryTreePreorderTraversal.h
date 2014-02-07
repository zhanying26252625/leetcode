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