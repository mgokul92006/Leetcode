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
    int path(TreeNode* root){
        if(root==NULL)
        return 0;
        int c=0;
        queue<tuple<TreeNode*,int>>q;
        q.push({root,root->val});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [node,maxi]=q.front();
                q.pop();
                if(node->val>=maxi)
                c++;
                if(node->left){
                    if(node->left->val>maxi){
                        q.push({node->left,node->left->val});
                    }
                    else
                        q.push({node->left,maxi});
                }
                if(node->right){
                    if(node->right->val>maxi){
                        q.push({node->right,node->right->val});
                    }
                    else
                        q.push({node->right,maxi});
                }
            }
        }
        return c;
    }
    int goodNodes(TreeNode* root) {
        return path(root);
    }
};