/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: C++
@Datetime: 16-07-28 05:57
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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        int len = 0;
        while (p1 != NULL) {
            p1 = p1->next;
            ++len;
        }
        
        int i = len - n;
        while (i > 0) {
            p2 = p2->next;
            --i;
        }
        
        return p2;
    }
};


