/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-07-30 05:15
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
    void insertSortList(ListNode *helper, ListNode *node) {
        ListNode *p = helper;
        // find the first node that has val > node->val
        while (p->next != NULL) {
            if (p->next->val > node->val) break;
            p = p->next;
        }
        
        // insert node at p->next
        node->next = p->next;
        p->next = node;
    }

    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return head;
        
        ListNode *helper = new ListNode(0x80000000);
        ListNode *p = head;
        while (p != NULL) {
            ListNode *q = p->next;
            p->next = NULL;
            insertSortList(helper, p);
            p = q;
        }
        
        return helper->next;
    }
};