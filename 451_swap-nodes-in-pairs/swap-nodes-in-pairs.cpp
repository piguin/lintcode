/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-07-30 05:45
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
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode helper(0x80000000);
        helper.next = head;
        
        // swap p->next and p->next->next
        ListNode *p = &helper;
        while (p->next != NULL && p->next->next != NULL) {
    		ListNode *a = p->next;
    		ListNode *b = a->next;
    		ListNode *c = b->next;
    
    		p->next = b;
    		b->next = a;
    		a->next = c;
    
    		p = a;
        }
        
        return helper.next;
    }
};