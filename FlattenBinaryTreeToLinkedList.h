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

















