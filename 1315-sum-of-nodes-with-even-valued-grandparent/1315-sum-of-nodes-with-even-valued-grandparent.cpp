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
    int bfs(TreeNode* root){
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto r=q.front();
            q.pop();
            if(r->left!=NULL && r->left->left!=NULL && r->val%2==0)
            sum=sum+r->left->left->val;
            if(r->left!=NULL && r->left->right!=NULL && r->val%2==0)
            sum=sum+r->left->right->val;
            if(r->right!=NULL && r->right->left!=NULL && r->val%2==0)
            sum=sum+r->right->left->val;
            if(r->right!=NULL && r->right->right!=NULL && r->val%2==0)
            sum=sum+r->right->right->val;
            if(r->left){
            q.push(r->left);
            }
            if(r->right)
            q.push(r->right);
        }
        return sum;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return bfs(root);
    }
};