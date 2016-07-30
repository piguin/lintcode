/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 16-07-26 05:10
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
    template <class T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
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
                    
                    // postorder traversal visit node here
                    swap(peek->left, peek->right);
                }
                continue;
            }
            
            stack.push_back(p);
            p = p->left;
        }
    }
};