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
    bool flag=1;
    TreeNode* path(TreeNode* root,int val){
        if(root==NULL && flag){
            flag=0;
            return new TreeNode(val);
        }
        if(root==NULL)
        return root;
        if(root->val>val){
            root->left=path(root->left,val);
        }
        else
            root->right=path(root->right,val);
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return path(root,val);
    }
};