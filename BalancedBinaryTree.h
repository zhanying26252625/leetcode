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