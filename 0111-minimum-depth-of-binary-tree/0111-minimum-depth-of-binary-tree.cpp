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
    int mini(TreeNode* root){
        if(root==NULL)
        return INT_MAX;
        if(root->left==NULL && root->right==NULL)
        return 1;
        int l=mini(root->left);
        int r=mini(root->right);
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
        int d=mini(root);
        if(d==INT_MAX)
        return 0;
        return d;
    }
};