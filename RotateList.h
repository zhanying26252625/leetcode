/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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

    ListNode *rotateRight(ListNode *head, int k) {
        
        if(!head){
            return head;
        }
        
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur -> next;
            ++len;
        }
        
        k = k%len;
        if(k==0){
            return head;
        }
        
        k = len - k;
        
        ListNode* pre = head;
        cur = head;
        
        int i = 0;
        while(i!=k){
            if(i<k-1)
                pre = pre -> next;
            cur = cur ->next;
            ++i;
        }
        pre->next = NULL;
        
        ListNode* newHead = cur;
        ListNode* tail = cur; 
        while(tail->next){
            tail = tail->next;
        }
        
        tail->next = head;
        
        return newHead;
        
    }
    
};