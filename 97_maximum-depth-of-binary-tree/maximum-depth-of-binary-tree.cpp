/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/maximum-depth-of-binary-tree
@Language: C++
@Datetime: 16-07-26 04:56
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
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // return maxDepthResursion(root);
        return maxDepthLoop(root);
    }

    int maxDepthResursion(TreeNode *root) {
        if (root == NULL) return 0;
        return max(maxDepthResursion(root->left), maxDepthResursion(root->right)) + 1;
    }
    
    int maxDepthLoop(TreeNode *root) {
        int maxDepth = 0;
        
        // need to implement post order travesal
        vector<TreeNode *> stack;
        TreeNode *p = root;
        TreeNode *visited = NULL;
        while (stack.size() != 0 || p != NULL) {
            if (p == NULL) {
                TreeNode *peek = stack.back();
                if (peek->right != NULL && peek->right != visited) {
                    p = peek->right;
                }
                else {
                    visited = peek; // mark current node as visited
                    stack.pop_back(); // only pop the parent when both left and right are visited
                    p = NULL;
                }
                
                continue;
            }
            
            stack.push_back(p);
            maxDepth = max(maxDepth, stack.size());
            p = p->left;
        }
        
        return maxDepth;
    }
};