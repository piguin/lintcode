/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 16-07-26 05:05
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
    int min(int a, int b) {
        return a < b ? a : b;
    }

    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        int minDepth = 0x7fffffff; // int max
        vector<TreeNode *> stack;
        TreeNode *p = root;
        TreeNode *visited = NULL;
        while (p != NULL || stack.size() != 0) {
            if (p == NULL) {
                auto peek = stack.back();
                if (peek->right != NULL && peek->right != visited) {
                    p = peek->right;
                }
                else {
                    visited = peek;
                    stack.pop_back();
                    p = NULL;
                }
                
                continue;
            }
            
            stack.push_back(p);
            if (p->left == NULL && p->right == NULL) {
                // leaf node, save the minDepth
                minDepth = min(minDepth, stack.size());
            }
            p = p->left;
        }
        return minDepth;
    }
};