/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-07-26 05:21
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
    string pathToString(vector<TreeNode *> &path) {
        string ret;
        if (path.size() == 0) return ret;
        ret = std::to_string(path[0]->val);
        for (int i = 1; i < path.size(); ++i) {
            ret += "->";
            ret += std::to_string(path[i]->val);
        }
        return ret;
    }

    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
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
                // leaf node, log the path
                ret.push_back(pathToString(stack));
            }
            p = p->left;
        }
        return ret;
    }
};