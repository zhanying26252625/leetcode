/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *deleteDuplicates(ListNode *head) {
        
        if(head==NULL)
            return NULL;
            
        ListNode* tail = head;
        int tailVal = tail->val;
        ListNode* cur = head->next;
        
        while(cur){
            if(cur->val!=tailVal){
                tailVal=cur->val;
                tail->next->val = tailVal;
                tail=tail->next;
            }
            cur=cur->next;
        }
        
        //deleteNodes(tail->next);
        tail->next = NULL;
        
        return head;
    }
};