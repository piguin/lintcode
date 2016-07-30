/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-07-28 04:51
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        while (p->next != NULL) {
            if (p->val == p->next->val) {
                // delete p->next
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};