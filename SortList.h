/*
Sort a linked list in O(n log n) time using constant space complexity.
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergetSort(head);    
    }

    ListNode *mergetSort(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * frontHead = head, * backHead = split(head);
        frontHead = mergetSort(frontHead);
        backHead = mergetSort(backHead);
        return merge(frontHead, backHead);
    }

    ListNode * split(ListNode * head) {
        ListNode * fastNode = head, * slowNode = head;
        while (fastNode->next != NULL && fastNode->next->next != NULL) fastNode = fastNode->next->next, slowNode = slowNode->next;
        head = slowNode->next;
        slowNode->next = NULL;
        return head;
    }

    ListNode * merge(ListNode * frontHead, ListNode * backHead) {
        ListNode * head = new ListNode(-1), * curNode = head;
        while (frontHead != NULL || backHead != NULL) {
            if (backHead == NULL || (frontHead != NULL && frontHead->val <= backHead->val)) curNode->next = frontHead, frontHead = frontHead->next;
            else curNode->next = backHead, backHead = backHead->next;
            curNode = curNode->next;
        }
        return deleteNode(head);
    }

    ListNode * deleteNode(ListNode * curNode) {
        ListNode * toDel = curNode;
        curNode = curNode->next;
        delete toDel;
        return curNode;
    }
};