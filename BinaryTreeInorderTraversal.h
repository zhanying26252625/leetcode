/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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

    //iterative
    vector<int> inorderTraversal(TreeNode *root) {
        
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        
        while(curNode||!s.empty()){
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                TreeNode* n= s.top();
                s.pop();
                v.push_back(n->val);
                curNode=n->right;
            }
            
        }
        
        return v;
    }
};





