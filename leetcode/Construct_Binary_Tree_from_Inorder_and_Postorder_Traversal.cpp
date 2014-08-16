//Construct Binary Tree from Inorder and Postorder Traversal 
//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

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
    unordered_map <int,int> inorder_map;
    
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int in_st, int in_end, int po_st, int po_end) {
        if(in_st > in_end || po_st > po_end) return NULL;
        
        TreeNode* parent = new TreeNode(postorder[po_end]);
        int i = inorder_map[postorder[po_end]];
        parent->left = build(inorder, postorder, in_st, i-1, po_st, po_st+(i-1-in_st));
        parent->right = build(inorder, postorder, i+1, in_end, (po_end - 1)-(in_end-(i+1))  ,po_end-1);
        return parent;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        int n = postorder.size();
        return build(inorder, postorder, 0, n-1, 0, n-1);
    }
};
