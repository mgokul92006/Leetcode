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
    bool validate(TreeNode* root,long long mini,long long maxi){
        if(root==NULL)
        return 1;
        int left=0,right=0;
        if(root->val>mini)
            left=validate(root->left,mini,root->val);
        if(root->val<maxi)
            right=validate(root->right,root->val,maxi);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};