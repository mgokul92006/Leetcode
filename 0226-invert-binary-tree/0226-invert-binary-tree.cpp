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
    void post(TreeNode* root){
        if(root==NULL)
        return;
        swap(root->left,root->right);
        post(root->left);
        post(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        post(root);
        return root;
    }
};