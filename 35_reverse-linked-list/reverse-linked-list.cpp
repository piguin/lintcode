/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 16-07-25 03:41
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    void swap(ListNode *&a, ListNode *&b) {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *p = head;
        ListNode *q = p->next;
        p->next = NULL;
        while (q != NULL) {
            swap(q->next, p);
            swap(p, q);
        }
        
        return p;
    }
};
