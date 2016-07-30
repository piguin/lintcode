/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-07-28 06:09
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0xf000000);
        ListNode *r = root;
        ListNode *p = l1;
        ListNode *q = l2;
        int carryOn = 0;
        while (p != NULL || q != NULL) {
            int val;
            if (p == NULL) {
                val = q->val + carryOn;
                q = q->next;
            }
            else if (q == NULL) {
                val = p->val + carryOn;
                p = p->next;
            }
            else {
                val = p->val + q->val + carryOn;
                p = p->next;
                q = q->next;
            }
            
            carryOn = val / 10;
            val %= 10;
            r->next = new ListNode(val);
            r = r->next;
        }
        
        if (carryOn != 0) {
            // carryOn == 1
            r->next = new ListNode(carryOn);
        }
        return root->next;
    }
};