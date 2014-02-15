/*
Sort a linked list using insertion sort.
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

    ListNode *insertionSortList(ListNode *head) {
        if(!head||!(head->next))
            return head;
        
        ListNode* nextNode = insertionSortList(head->next);
        return insert(head,nextNode);
    }
    
    ListNode* insert(ListNode* newNode, ListNode* head){
        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre = &dummy;
        
        while(pre->next&&newNode->val>pre->next->val)
            pre=pre->next;
        
        newNode->next=pre->next;
        pre->next=newNode;
        return dummy.next;
    }
    
};