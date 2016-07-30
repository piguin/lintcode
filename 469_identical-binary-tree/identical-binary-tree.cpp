/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/identical-binary-tree
@Language: C++
@Datetime: 16-07-30 03:58
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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;
        
        TreeNode *p = a;
        TreeNode *q = b;
        while (p != NULL || path1.size() != 0) {
            if (p == NULL) {
                if (q != NULL) return false;
                
                p = path1.back()->right;
                path1.pop_back();
                q = path2.back()->right;
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
};