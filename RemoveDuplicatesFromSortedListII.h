/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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

    ListNode *deleteDuplicates(ListNode *head) {
        
        if(head==NULL)
            return NULL;

        map<int,int> cache;
        
        ListNode* cur = head;
        while(cur){
            cache[cur->val]++;
            cur=cur->next;
        }
        
        for(map<int,int>::iterator iter = cache.begin() ; iter != cache.end(); ){
            if(iter->second>1){
                cache.erase(iter++);
            }
            else{
                ++iter;
            }
        }
        
        ListNode* h = NULL;
        ListNode* t = NULL;
        for(map<int,int>::iterator iter = cache.begin() ; iter != cache.end(); ++iter){
            ListNode* n = new ListNode(iter->first);
            if(!h){
                h = n;
                t = n;
            }
            else{
                t->next = n;
                t = n;
            }
        }
        
        return h;
    }
    
};

//O(1) space
//iterative
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next)
        {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = node->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
}
*/

//recursive
/*
  ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !(head->next) ) return head;
        
        if ( head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        int v = head->val;
        ListNode* next = head;
        while(next&&next->val==v){
            ListNode* n = next;
            next = next->next;
            delete n;
        }
        
        return deleteDuplicates(next);
        
  }
  */