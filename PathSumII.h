/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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

    vector<vector<int> > vv;
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        
        if(root==NULL)
            return vv;
            
        vector<int> path;
        pathSum(root,sum,path,0);
        return vv;
        
    }
    
    void pathSum(TreeNode *root, int sum, vector<int>& path, int preSum){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL&&root->right==NULL){
            if(sum==preSum+root->val){
                path.push_back(root->val);
                vv.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        path.push_back(root->val);
        pathSum(root->left,sum,path,preSum+root->val);
        pathSum(root->right,sum,path,preSum+root->val);
        path.pop_back();
    }
    
};