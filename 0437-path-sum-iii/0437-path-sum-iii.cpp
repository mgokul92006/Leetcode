/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int c = 0;
    void calculateSum(TreeNode* root, long long targetSum) {
        if (root == NULL)
            return;
        if (root->val == targetSum)
            c++;
        calculateSum(root->left, targetSum - root->val);
        calculateSum(root->right, targetSum - root->val);
    }
    void recur(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;
        calculateSum(root, targetSum);
        recur(root->left, targetSum);
        recur(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;
        recur(root, targetSum);
        return c;
    }
};