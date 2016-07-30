/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-07-25 04:09
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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;

        vector<TreeNode *> stack;
        TreeNode *p = root;
        while (stack.size() != 0 || p != NULL) {
            if (p == NULL) {
                p = stack.back()->right;
                stack.pop_back();
                continue;
            }
            
            ret.push_back(p->val);
            stack.push_back(p);
            p = p->left;
        }
        
        return ret;
    }
};
