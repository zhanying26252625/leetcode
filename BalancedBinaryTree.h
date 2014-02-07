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

    bool isBalanced(TreeNode *root, int& h){
        
        if(root==NULL){
            h=0;
            return true;
        }
        
        int left = 0;
        if( !isBalanced(root->left,left) )
            return false;
            
        int right = 0;
        if ( !isBalanced(root->right,right) )
            return false;
            
        h = max(left,right)+1;
        return abs(left-right)<=1;
    }

    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
        
        int h = 0;
        return isBalanced(root,h);
    }
};