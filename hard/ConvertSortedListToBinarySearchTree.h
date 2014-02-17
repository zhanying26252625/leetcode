/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

    //O(N), not O(NlgN)
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            ++len;
        }
    
        TreeNode* root = buildBST(0,len-1,head);
        
        return root;
    }
    
     TreeNode* buildBST(int b ,int e, ListNode*& head){
         if(b<=e){
             int m = b + (e-b)/2;
             TreeNode* n = new TreeNode(0);
             n->left = buildBST(b,m-1,head);
             n->val=head->val;
             head=head->next;
             n->right = buildBST(m+1,e,head);
             
             return n;
         }
         return NULL;
     }
    
};






