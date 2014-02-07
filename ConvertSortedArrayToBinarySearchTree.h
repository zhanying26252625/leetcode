/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

    TreeNode *sortedArrayToBST(vector<int> &num, int b , int e) {
        if(b<=e){
            int m = b + (e-b)/2;
            TreeNode* n = new TreeNode(num[m]);
            n->left = sortedArrayToBST(num,b,m-1);
            n->right = sortedArrayToBST(num,m+1,e);
            return n;
        }
        return NULL;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num,0,num.size()-1);
    }
    
};