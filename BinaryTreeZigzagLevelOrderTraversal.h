/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > vv;
        if(root==NULL)
            return vv;
            
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        int level = 1;
        
        while(!q.empty()){
            TreeNode* n =  q.front();
            q.pop();
            --size;
            v.push_back(n->val);
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
                
            if(0==size){
                if(level%2==0){
                    reverse(v.begin(),v.end());
                }
                vv.push_back(v);
                v.clear();
                size = q.size();
                ++level;
            }
        }
        
        return vv;
    }


    /*
void printLevelOrderZigZag(BinaryTree *root) {
  stack<BinaryTree*> currentLevel, nextLevel;
  bool leftToRight = true;
  currentLevel.push(root);
  while (!currentLevel.empty()) {
    BinaryTree *currNode = currentLevel.top();
    currentLevel.pop();
    if (currNode) {
      cout << currNode->data << " ";
      if (leftToRight) {
        nextLevel.push(currNode->left);
        nextLevel.push(currNode->right);
      } else {
        nextLevel.push(currNode->right);
        nextLevel.push(currNode->left);
      }
    }
    if (currentLevel.empty()) {
      cout << endl;
      leftToRight = !leftToRight;
      swap(currentLevel, nextLevel);
    }
  }
}

    */
};