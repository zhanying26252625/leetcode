/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

    ListNode* reverse(ListNode* head){
        if(!head||!(head->next)){
            return head;
        }
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
        
    }
    
    ListNode* interleave(ListNode* head, ListNode* head2){
        if(!head){
            return head2;
        }
        if(!head2){
            return head;
        }
        
        ListNode* newHead = head;
        head = head->next;
        newHead->next = interleave(head2,head);
        
        return newHead;
    }
    
    void reorderList(ListNode *head) {
        
        if(!head||!(head->next))
            return;
            
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow ->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        //reverse head2;
        head2 = reverse(head2);
        
        //interleave head head2
        head=interleave(head,head2);
        
    }
    
};



