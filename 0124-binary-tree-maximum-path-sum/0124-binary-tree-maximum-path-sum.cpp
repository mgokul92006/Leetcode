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
    int maxi=INT_MIN;
    int path(TreeNode* root){
        if(root==NULL)
        return 0;
        int l=path(root->left);
        int r=path(root->right);
        maxi=max(maxi,l+r+root->val);
        return max(0,root->val+max(l,r)) ;
    }
    int maxPathSum(TreeNode* root) {
        path(root);
        return maxi;
    }
};