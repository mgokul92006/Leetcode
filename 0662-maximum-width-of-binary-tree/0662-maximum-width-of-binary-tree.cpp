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
    int wid=0;
    void level(TreeNode* root) {
        queue < pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int s = q.size();
            long long mini=q.front().second;
            long long first=0,last=0;
            for (int i = 0; i < s; i++) {
                TreeNode* p = q.front().first;
                long long ind = q.front().second-mini;
                q.pop();
                if(i==0)
                first=ind;
                if(i==s-1)
                last=ind;
                if (p->left != NULL) {
                    q.push({p->left,(2*ind)+1});
                }
                if (p->right != NULL) {
                    q.push({p->right,2*ind+2});
                }
            }
            wid=max(wid,(int)(last-first+1));
        }
    }
    int widthOfBinaryTree(TreeNode* root) { level(root); 
    return wid;
    }
};