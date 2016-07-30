/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-07-30 03:52
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        vector<TreeNode *> stack;
        TreeNode *p = root;
        TreeNode *last = p;
        while (p != NULL || stack.size() != 0) {
            if (p == NULL) {
                p = stack.back();
                stack.pop_back();
            }
            
            // visit p
            if (p->right != NULL) {
                stack.push_back(p->right);
            }

            if (p != NULL && last != p) {
                last->left = NULL;
                last->right = p;
                last = p;
            }

            p = p->left;
        }
    }
};