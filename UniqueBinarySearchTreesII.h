/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

    //unordered_map<pair<int,int>, vector<TreeNode*> > cache;
    
    vector<TreeNode *> generateTrees(int b, int e){
        
        vector<TreeNode *> v;
        
        if(b>e){
            v.push_back(NULL);
            return v;
        }
            
        if(b==e){
            TreeNode* n = new TreeNode(b);
            v.push_back(n);
            return v;
        }
    
        for(int m = b; m <= e; ++m){
            vector<TreeNode *> left = generateTrees(b,m-1);
            vector<TreeNode *> right = generateTrees(m+1,e);
            
            for(int i = 0; i< left.size(); ++i){
                for(int j =0 ;j<right.size();++j){
                    TreeNode* n = new TreeNode(m);
                    n->left = left[i];
                    n->right = right[j];
                    v.push_back(n);
                }
            }
        }
        
        return v;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        
         return generateTrees(1,n);
    }
    
};