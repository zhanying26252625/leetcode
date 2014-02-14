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
        return deleteDuplicates1(head);
    }
    //recursive
    ListNode *deleteDuplicates2(ListNode *head) {
        if (!head || !(head->next) ) return head;
        if ( head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        ListNode* next = head->next;
        delete head;
        return deleteDuplicates(next);
    }
    //iterative
    ListNode *deleteDuplicates1(ListNode *head) {
        
        if(head==NULL||head->next==NULL)
            return head;
            
        ListNode* tail = head;
        int tailVal = tail->val;
        ListNode* cur = head->next;
        
        while(cur){
            if(cur->val!=tailVal){
                tail->next = cur;
                tail=tail->next;
                tailVal = tail->val;
                cur=cur->next;
            }else{
                ListNode* n = cur;
                cur=cur->next;
                delete n;
            }
        }
        
        tail->next = NULL;
        
        return head;
    }
    
};