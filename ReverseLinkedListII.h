/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
		//assume n and m are within the range and n >= m
        if(m==n)
            return head;
            
        //dummy head make life easier for case that m==1
        ListNode dummy(0);
        ListNode* newHead = &dummy;
        newHead->next = head;
        
        ListNode* preM = newHead;
        ListNode* nodeN = newHead;
        
        int index = 1 ;
        while(index<=n){
            if(index<m){
                preM = preM->next;
            }
            nodeN = nodeN->next;
            ++index;
        }

        ListNode* nodeM = preM->next;
        preM->next = NULL;
        
        ListNode* postN = nodeN->next;
        nodeN->next = NULL;
  
        preM->next = reverse(nodeM);
        nodeM->next = postN;

        return newHead->next;
    }
    
};