/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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

    struct MyComp{
        bool operator()(ListNode* n1, ListNode* n2){
            return n1->val > n2->val;
        }  
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        if(lists.size()==0){
            return NULL;
        }
        
        if(lists.size()==1){
            return lists[0];
        }
        
        priority_queue<ListNode*, deque<ListNode*>, MyComp > heap;
        
        for(int i = 0 ; i < lists.size(); ++i ){
            if(lists[i]!=NULL)
                heap.push(lists[i]);
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(heap.empty()==false){
            ListNode* newNode = heap.top();
            heap.pop();
            if(newNode->next){
                heap.push(newNode->next);
            }
            
            if(!head){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
        return head;
        
    }
};