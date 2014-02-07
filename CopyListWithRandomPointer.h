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