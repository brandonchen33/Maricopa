//Convert Sorted Array to Binary Search Tree.
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *AtoBST(vector<int> &num, int start, int end) {
        if(start > end) {
            return NULL;
        }
        TreeNode* parent = new TreeNode(num[start + (end-start)/2]);
        parent->left = AtoBST(num, start, (start + (end-start)/2 - 1));
        parent->right = AtoBST(num, (start + (end-start)/2 + 1), end);
        return parent;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return AtoBST(num, 0, num.size()-1);
    }
};
