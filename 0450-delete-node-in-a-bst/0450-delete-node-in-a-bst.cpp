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
    TreeNode* find_min(TreeNode* root) {
        if (root->left == NULL)
            return root;
        return find_min(root->left);
    }
    TreeNode* function(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val < key) {
            root->right = function(root->right, key);
        } else if (root->val > key) {
            root->left = function(root->left, key);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* succ = find_min(root->right);
            root->val = succ->val;
            root->right = function(root->right, succ->val);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return function(root, key);
    }
};