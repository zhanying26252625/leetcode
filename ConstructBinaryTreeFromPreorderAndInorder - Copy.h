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
        
        return buildTree(preorder,0,preorder.size(),inorder,0,inorder.size());
        
    }
};