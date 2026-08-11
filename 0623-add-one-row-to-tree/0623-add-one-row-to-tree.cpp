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
    TreeNode* dp(TreeNode* root, int val, int depth) {
        if (root == NULL)
            return 0;
        if (depth == 1) {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        queue<tuple<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto [node, d] = q.front();
                q.pop();
                if (d + 1 == depth) {
                    TreeNode* n = new TreeNode(val);
                    TreeNode* n1 = new TreeNode(val);
                    TreeNode* temp1 = node->left;
                    TreeNode* temp2 = node->right;
                    node->left = n;
                    node->right = n1;
                    n->left = temp1;
                    n1->right = temp2;
                }
                if (node->left) {
                    q.push({node->left, d + 1});
                }
                if (node->right) {
                    q.push({node->right, d + 1});
                }
            }
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return dp(root, val, depth);
    }
};