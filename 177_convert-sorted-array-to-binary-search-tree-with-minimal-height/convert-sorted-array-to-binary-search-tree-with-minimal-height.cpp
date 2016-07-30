/*
@Copyright:LintCode
@Author:   qili
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 16-07-28 06:48
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
    TreeNode *sortedArrayToBST(vector<int> &A, int start, int end) {
        if (start == end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *ret = new TreeNode(A[mid]);
        ret->left = sortedArrayToBST(A, start, mid);
        ret->right = sortedArrayToBST(A, mid + 1, end);
        return ret;
    }
    
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return sortedArrayToBST(A, 0, A.size());
    }
};


