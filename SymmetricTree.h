/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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

    //recursive
    bool isSymmetric(TreeNode * l, TreeNode * r) {
                
        if( (l==NULL) ^ (r==NULL) )
            return false;
            
        if(!l)
            return true;
        
        if(l->val!=r->val)
            return false;
        
        return isSymmetric(l->left,r->right) && isSymmetric(l->right,r->left);
    }


    bool isSymmetric(TreeNode *root) {
        
        if(root==NULL)
            return true;
            
        //return isSymmetric(root->left,root->right);
        return isSymmetric2(root);
     
    }
    
    //iterative
    bool isSymmetric2(TreeNode *root){
        
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        vector<int> v;
        
        while(!q.empty()){
            
            TreeNode* n = q.front();
            q.pop();
            --size;
            
            if(n!=NULL){
                v.push_back(n->val);
                q.push( n->left?n->left: NULL);
                q.push( n->right?n->right: NULL);
            }
            else{
                v.push_back('#');
            }
            
            if(size==0){
                
                size=q.size();
                
                for(int i = 0 , j = v.size()-1; i<j ; ++i,--j){
                    if(v[i]!=v[j])
                        return false;
                }
                v.clear();
            }
        }
        
        return true;
    }
    
};







