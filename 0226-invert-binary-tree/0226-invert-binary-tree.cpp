/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root){
        if(root==NULL)
        return;
        if(root->left !=NULL || root->right!=NULL)
        swap(root->left,root->right);
        inorder(root->left);
        inorder(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        inorder(root);
        return root;
    }
};