/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 //any binary tree
 
class Solution {
public:
     void connect(TreeLinkNode *root) {
        connect2(root);
        
    }
    
    //queue
    void connect1(TreeLinkNode *root) {
        if(root==NULL)
            return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        int count = 1;
        vector<TreeLinkNode*> v;
        
        while( !q.empty() ){
            
            TreeLinkNode* node = q.front();
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
                
            v.push_back(node);
            --count;
            
            if(count==0){
                count = q.size();
                v.push_back(NULL);
                for(int i = 0 ; i < v.size()-1; ++i){
                    v[i]->next=v[i+1];
                }
                v.clear();
            }
        
        }
    }
    
    //no queue
    void connect2(TreeLinkNode *root) {
        if(root==NULL)
            return;
        
        //如果右孩子不为空，左孩子的next是右孩子。  
        //反之，找root next的至少有一个孩子不为空的节点  
        if (root->left != NULL) {  
            if (root->right != NULL) {  
                root->left->next = root->right;  
            }  
            else {  
                TreeLinkNode* p = root->next;  
                while (p != NULL && p->left == NULL && p->right == NULL)  
                    p = p->next;  
                if (p != NULL)  
                    root->left->next = p->left == NULL ? p->right : p->left;  
            }  
        }  
          
        //右孩子的next 根节点至少有一个孩子不为空的next  
        if (root->right != NULL) {  
                TreeLinkNode* p = root->next;  
                while (p != NULL && p->left == NULL && p->right == NULL)  
                    p = p->next;  
                if (p != NULL)  
                    root->right->next = p->left == NULL ? p->right : p->left;  
        }  
        
        connect(root->right);      
        connect(root->left);  
        
    }
    
};