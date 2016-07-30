/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-07-28 06:23
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
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) return head;
        
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n; ++i) p = p->next;
        // remove the first
        if (p == NULL) return head->next;
        
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        // delete q
        q->next = q->next->next;
        return head;
    }
};


