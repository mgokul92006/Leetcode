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
    pair<TreeNode*,int> post(TreeNode* root){
        if(root==NULL)
        return {root,0};
        auto[a,b]=post(root->left);
        root->left=a;
        auto[c,d]=post(root->right);
        root->right=c;
        if(b+d+root->val==0){
            return {NULL,0};
        }
        return {root,root->val+b+d};
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* n=post(root).first;
        return n;
    }
};