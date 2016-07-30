/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/insert-node-in-a-binary-search-tree
@Language: C++
@Datetime: 16-07-28 03:36
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL) return node;
        TreeNode *p = root;
        while (p != NULL) {
            TreeNode **next;
            if (p->val > node->val)
                next = &p->left;
            else  // no duplicate: p->val < node->val
                next = &p->right;
                
            if (*next == NULL) {
                *next = node;
                break;
            }
            else {
                p = *next;
            }
        }
        
        return root;
    }
};