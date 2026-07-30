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
    int level(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum1 = 0;
        while (!q.empty()) {
            int s = q.size();
            sum1=0;
            for (int i = 0; i < s; i++) {
                auto k = q.front();
                sum1 =sum1+ k->val;
                q.pop();
                if (k->left != NULL)
                    q.push(k->left);
                if (k->right != NULL)
                    q.push(k->right);
            }
        }
        return sum1;
    }
    int deepestLeavesSum(TreeNode* root) { return level(root, 0); }
};