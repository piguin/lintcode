/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-07-28 04:02
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    template <class T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    
    ListNode *partition(ListNode *head, int x) {
    	ListNode *p = new ListNode(0xf0000000);
    	p->next = head;
    
    	ListNode *q = new ListNode(0xf0000000);
    	q->next = NULL;
    
    	ListNode *r = p;
    	ListNode *s = q;
    	while (r->next != NULL) {
    		if (r->next->val >= x) {
    			s->next = r->next;
    			s = s->next;
    			r->next = s->next;
    			s->next = NULL;
    		}
    		else {
    			r = r->next;
    		}
    	}
    	
    	if (q->next != NULL)
    	    r->next = q->next;
    
    	return p->next;
    }

};


