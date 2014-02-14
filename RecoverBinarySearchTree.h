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