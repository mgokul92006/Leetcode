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
    int ans = 0;
    void path(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, root->val, root->val});
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto [node, mini, maxi] = q.front();
                q.pop();
                ans = max(ans, abs(maxi - mini));
                if (node->left) {
                    int a=-1,b=-1;
                    if(mini>node->left->val)
                    a=node->left->val;
                    if(maxi<node->left->val)
                    b=node->left->val;
                    if(a!=-1 && b!=-1)
                    q.push({node->left, a, b});
                    else if(a==-1 && b==-1)
                    q.push({node->left,mini,maxi});
                    else if(b!=-1)
                    q.push({node->left,mini,b});
                    else
                    q.push({node->left,a,maxi});
                }
                if (node->right) {
                    int a=-1,b=-1;
                    if(mini>node->right->val)
                    a=node->right->val;
                    if(maxi<node->right->val)
                    b=node->right->val;
                    if(a!=-1 && b!=-1)
                    q.push({node->right, a, b});
                    else if(a==-1 && b==-1)
                    q.push({node->right,mini,maxi});
                    else if(b!=-1)
                    q.push({node->right,mini,b});
                    else
                    q.push({node->right,a,maxi});
                }
            }
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        path(root);
        return ans;
    }
};