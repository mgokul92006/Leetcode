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
    int inorder(TreeNode* root){
        if(root==NULL)
        return 0;
        int l=inorder(root->left);
        int r=inorder(root->right);
        if(l==0 && r==0)
        return 1;
        if(l==0)
        return r+1;
        if(r==0)
        return l+1;
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
        return inorder(root);
    }
};