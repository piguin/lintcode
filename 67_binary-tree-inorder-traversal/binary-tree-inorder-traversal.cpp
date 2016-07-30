/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-07-25 04:20
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;
        
        vector<TreeNode *> stack;
        TreeNode *p = root;
        while (p != NULL || stack.size() != 0) {
            if (p == NULL) {
                p = stack.back()->right;
                ret.push_back(stack.back()->val);
                stack.pop_back();
                continue;
            }
            
            stack.push_back(p);
            p = p->left;
        }
        
        return ret;
    }
};