/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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

    //maxPath,maxHeight
    typedef pair<int,int> Val;
    
    int maxPathsumHelper(TreeNode* root, Val& v){
        
        int maxChildPath = INT_MIN;
        int maxRootPath = root->val;
        int maxHeight = root->val;
        
        if(root->left){
            Val leftV;
            maxPathsumHelper(root->left,leftV);
            if(leftV.second>0)
                maxRootPath += leftV.second;
                
            maxChildPath = max(maxChildPath, leftV.first);
            maxHeight = max(maxHeight,root->val+leftV.second);
        }
        
        if(root->right){
            Val rightV;
            maxPathsumHelper(root->right,rightV);
            if(rightV.second>0)
                maxRootPath += rightV.second;
                
            maxChildPath = max(maxChildPath,rightV.first);
            maxHeight = max(maxHeight,root->val+rightV.second);
        }
        
        v.first = max(maxChildPath,maxRootPath);
        v.second = maxHeight;

        return v.first;
    }
    
    int maxPathSum(TreeNode *root) {
        if(!root)
            return 0;
            
        Val v;
        maxPathsumHelper(root,v);
        return v.first;
    }
};
