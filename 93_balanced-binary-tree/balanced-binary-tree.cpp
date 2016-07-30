/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-07-26 05:47
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
    int max(int a, int b) {
        return a > b ? a : b;
    }

    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        vector<TreeNode *> path;
        std::map<TreeNode *, int> nodeHeight;
        TreeNode *p = root;
        TreeNode *visited = NULL;
        while (p != NULL || path.size() != 0) {
            if (p == NULL) {
                auto peek = path.back();
                if (peek->right != NULL && peek->right != visited) {
                    p = peek->right;
                }
                else {
                    // visit peek here, calculate height
                    int left = peek->left == NULL ? 0 : nodeHeight[peek->left];
                    int right = peek->right == NULL ? 0 : nodeHeight[peek->right];
                    int diff = left - right;
                    if (diff > 1 || diff < -1) return false;
                    nodeHeight[peek] = max(left, right) + 1;
                    
                    visited = peek;
                    path.pop_back();
                    p = NULL;
                }
                continue;
            }
            
            path.push_back(p);
            p = p->left;
        }
        
        return true;
    }
};