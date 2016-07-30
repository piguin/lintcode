/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 16-07-28 05:50
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
    
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *root1 = new ListNode(0xf0000000);
        ListNode *root2 = new ListNode(0xf0000000);
        root1->next = l1;
        root2->next = l2;
        ListNode *p = root1;
        ListNode *q = root2;
        
        while (p->next != NULL && q->next != NULL) {
            if (p->next->val > q->next->val) {
                swap(p->next, q->next);
                p = p->next;
                swap(p->next, q->next);
            } else {
                p = p->next;
            }
        }
        
        if (q->next != NULL) p->next = q->next;
        return root1->next;
    }
};