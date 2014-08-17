//Maximum Depth of Binary Tree 
//Given a binary tree, find its maximum depth.
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL) return 0;
        
        if(root->left==NULL && root->right != NULL) 
            return maxDepth(root->right) + 1;
        else if(root->left != NULL && root->right == NULL)
            return maxDepth(root->left) + 1;
        else
            return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};
