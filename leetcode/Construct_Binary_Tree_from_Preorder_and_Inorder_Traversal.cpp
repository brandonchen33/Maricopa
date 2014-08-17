//Construct Binary Tree from Preorder and Inorder Traversal 
//Given preorder and inorder traversal of a tree, construct the binary tree.
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
    unordered_map<int,int> map_index;
    TreeNode *build(vector<int> &pre, vector<int>&in, int in_st, int in_end, int pre_st, int pre_end){
        if (in_end < in_st || pre_end < pre_st) 
            return NULL;
            
        TreeNode *parent = new TreeNode(pre[pre_st]);
        int i = map_index[pre[pre_st]];
        parent->left = build(pre, in, in_st, i-1, pre_st+1, pre_st+(i-in_st) );
        parent->right = build(pre, in,i+1, in_end, pre_end-(in_end-(i+1)) ,pre_end);
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size(); 
        
        for(int i = 0; i < n; i++) {
            map_index[inorder[i]] = i;
        }
        
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};
