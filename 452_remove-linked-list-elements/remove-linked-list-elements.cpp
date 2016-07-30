/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-07-25 00:26
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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // skip all front nodes the has head->val = val
        while (head != NULL && head->val == val)
            head = head->next;

        // return empty list
        if (head == NULL) return NULL;
        
        // head is not NULL
        ListNode *p = head;
        while (p != NULL) {
            ListNode *q = p->next;
            if (q != NULL && q->val == val) {
                p->next = q->next;
                // free q
                continue;
            }
            
            p = p->next;
        }
        
        return head;
    }
};