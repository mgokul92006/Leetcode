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
    int complete(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        bool f=1;
        while(!q.empty() && f){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                if(node==NULL)
                {
                    f=0;
                    break;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        while(!q.empty()){
            if(q.front()) return 0;
            q.pop();
        }
        return 1;
    }
    bool isCompleteTree(TreeNode* root) {
        return complete(root);
    }
};