/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if (fastNode == slowNode) break;
        }
        if (fastNode != slowNode) return NULL;

        fastNode = head;
        while (fastNode != slowNode) {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        return fastNode;
    }
};