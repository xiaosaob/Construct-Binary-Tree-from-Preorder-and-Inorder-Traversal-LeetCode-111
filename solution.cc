// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, 0, inorder, 0, preorder.size());
    }
    
    TreeNode *helper(vector<int> &preorder, int preStart, vector<int> &inorder, int inStart, int num) {
        if(num <= 0) return NULL;
        int rootVal = preorder[preStart];
        int inorderIdx = 0;
        for(int i = 0; i < num; ++i) {
            if(inorder[inStart+i] == rootVal) {
                inorderIdx = inStart+i;
                break;
            }
        }
        
        TreeNode *left = helper(preorder, preStart+1, inorder, inStart, inorderIdx-inStart);
        TreeNode *right = helper(preorder, preStart+(inorderIdx-inStart)+1, inorder, inorderIdx+1, num-1-(inorderIdx-inStart));
        TreeNode *root = new TreeNode(rootVal);
        root->left = left;
        root->right = right;
        return root;
    }
};
