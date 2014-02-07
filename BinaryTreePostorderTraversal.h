/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode *root) {
             
        vector<int> v;
        if(root==NULL)
            return v;
            
        stack<TreeNode*> s;
        TreeNode * curNode = root;
        unordered_set<TreeNode*> cache;
        
        while(curNode||!s.empty()){
            
            if(curNode){
                s.push(curNode);
                curNode=curNode->left;
            }
            else{
                curNode = s.top();
                s.pop();
                if(curNode->right&&cache.count(curNode->right)==0){ //if right is not visited
                    s.push(curNode);
                    curNode = curNode->right;
                }
                else{ //if right is already visited
                    v.push_back(curNode->val);
                    cache.insert(curNode);
                    curNode = NULL;
                }
            }
            
        }
        
        return v;    
    }
};