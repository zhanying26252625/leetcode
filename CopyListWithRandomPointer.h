/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList2(head);
    }
    
    //O(1) space, very tricky
    RandomListNode *copyRandomList2(RandomListNode *head) {
        //stage1
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        //stage2
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        //stage3
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
        
    }
    
    //O(N) space
    RandomListNode *copyRandomList1(RandomListNode *head) {
        
        if(!head)
            return NULL;
            
        unordered_map<RandomListNode* , RandomListNode*> cache;
        cache[NULL]=NULL;
        
        RandomListNode* cur = head;
        while(cur){
            RandomListNode* copy = new RandomListNode(cur->label);
            cache[cur]=copy;
            cur=cur->next;
        }
        
        cur = head;
        while(cur){
            RandomListNode* copy = cache[cur];
            copy->next = cache[cur->next];
            copy->random = cache[cur->random];
            cur=cur->next;
        }
        
        return cache[head];
        
    }
};