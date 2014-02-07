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