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
