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
    vector<int>a;
    vector<vector<int>>b;
    void path(TreeNode* root, int& targetSum, int sum) {
        if (root == NULL)
            return;
        a.push_back(root->val);
        if (sum+root->val == targetSum && root->left == NULL && root->right == NULL) {
            b.push_back(a);
        } else {
            path(root->left, targetSum,sum+root->val );
            path(root->right, targetSum,sum+root->val);
        }
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path(root, targetSum, 0);
        return b;
    }
};