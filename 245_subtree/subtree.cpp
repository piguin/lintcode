/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 16-07-30 04:08
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
    bool sameTree(TreeNode *T1, TreeNode *T2) {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        
        TreeNode *p = T1;
        TreeNode *q = T2;
        while (p != NULL || path1.size() != 0) {
            if (p == NULL) {
                if (q != NULL) return false;
                p = path1.back()->right;
                q = path2.back()->right;
                path1.pop_back();
                path2.pop_back();
                continue;
            }
            
            if (q == NULL || p->val != q->val) return false;
            path1.push_back(p);
            path2.push_back(q);
            p = p->left;
            q = q->left;
        }
        
        return q == NULL && path2.size() == 0;
    }

    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) return true;
        vector<TreeNode *> stack;
        TreeNode *p = T1;
        while (p != NULL || stack.size() != 0) {
            if (p == NULL) {
                p = stack.back()->right;
                stack.pop_back();
                continue;
            }
            
            if (p->val == T2->val && sameTree(p, T2)) return true;
            stack.push_back(p);
            p = p->left;
        }
        return false;
    }
};