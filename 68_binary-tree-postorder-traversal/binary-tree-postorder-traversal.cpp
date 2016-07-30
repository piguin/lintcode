/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-07-25 04:44
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;
        
        vector<TreeNode *> stack;
        TreeNode *p = root;
        TreeNode *visited = NULL;
        while (p != NULL || stack.size() != 0) {
            if (p == NULL) {
                auto back = stack.back();
                if (back->right != NULL && back->right != visited) {
                    // visit first, pop later
                    p = back->right;
                }
                else {
                    // right is NULL or has been visited already, now visit this node
                    visited = back;
                    ret.push_back(back->val);
                    stack.pop_back();
                    p = NULL; // set p to NULL to trigger another pop
                }
                
                continue;
            }
            
            stack.push_back(p);
            p = p->left;
        }
    }
};