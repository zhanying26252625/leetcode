/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        if (NULL == head || n <= 0) return head;
        ListNode *fastNode = head, *slowNode = head;
        while (fastNode != NULL && n > 0) fastNode = fastNode->next, n--;
        if (fastNode == NULL) {
            if (n == 0) {
                head = head->next;
                delete slowNode;
            }
            return head;
        }
        while (fastNode->next != NULL) fastNode = fastNode->next, slowNode = slowNode->next;
        ListNode* nextNode = slowNode->next;
        slowNode->next = nextNode->next;
        delete nextNode;
        return head;
    }
    
};


