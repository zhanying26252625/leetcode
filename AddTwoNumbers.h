/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       ListNode *start=NULL, *tail=NULL;
       ListNode *L1=l1, *L2=l2;
       int carry=0;
       int sum=0;
       while(L1!=NULL||L2!=NULL||carry!=0)
       {
           int num1=(L1==NULL)? 0 :L1->val;
           int num2=(L2==NULL)? 0 :L2->val;
           sum=num1+num2+carry;
           carry=sum/10;
           sum%=10;
           
		   //we can use a dummy head node to get-rid-of this if-else
           if(start==NULL)
           {
               start=new ListNode(sum);
               tail=start;
           }
           else
           {
               tail->next=new ListNode(sum);
               tail=tail->next;
           }
           
           L1=(L1==NULL)? NULL :L1->next;
           L2=(L2==NULL)? NULL :L2->next;
       }
       
       return start;
    }
};