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
    unordered_map<TreeNode*,int[2]>dp;
    int dpCalculate(TreeNode* root,int flag){
        if(root==NULL)
        return 0;
        int sum=0;
        if(dp[root][flag]!=0)
            return dp[root][flag];
        if(flag==0)
            sum=max(sum,root->val+dpCalculate(root->left,1)+dpCalculate(root->right,1));
        sum=max(sum,dpCalculate(root->left,0)+dpCalculate(root->right,0));
        return dp[root][flag]=sum;
    }
    int rob(TreeNode* root) {
        return dpCalculate(root,0);
    }
};