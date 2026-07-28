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
    int path(TreeNode* root,int& tar,int sum){
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==tar)
            return 1;
            return 0;
        }
        int l=path(root->left,tar,sum+root->val);
        int r=path(root->right,tar,sum+root->val);
        return l+r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path(root,targetSum,0);
    }
};