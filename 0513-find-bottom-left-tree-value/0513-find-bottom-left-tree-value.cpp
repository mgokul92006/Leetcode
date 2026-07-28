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
    int a=0;
    void level(TreeNode* root){
        if(root==NULL)
        return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>b;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                b.push_back(node->val);
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            if(!b.empty())
            a=b[0];
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        level(root);
        return a;
    }
};