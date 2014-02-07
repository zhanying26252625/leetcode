/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
        
        if(!head||!(head->next))
            return head;
        
        ListNode* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        
        ListNode* cur = head;
        ListNode* pre = head;
        int i = 0;
        
        while( cur && i < k){
            if(i<k-1)
                pre=pre->next;
            cur = cur->next;
            ++i;
        }

        //less than k elements
        if(i<k){
            return head;
        }
    
        pre->next=NULL;
        ListNode* node = reverseKGroup(cur,k);
        
        ListNode* newHead = reverse(head);
        head->next=node;
        
        assert(pre==newHead);
        
        return pre;
    }
    
};