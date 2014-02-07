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