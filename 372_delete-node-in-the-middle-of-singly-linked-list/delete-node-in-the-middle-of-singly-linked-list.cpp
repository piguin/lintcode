/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/delete-node-in-the-middle-of-singly-linked-list
@Language: C++
@Datetime: 16-07-25 23:54
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // this passing style doesn't allow front node to be deleted
        if (node == NULL) return;
        if (node->next == NULL) return; // undefined behavior
        
        node->val = node->next->val;
        node->next = node->next->next;
    }
};