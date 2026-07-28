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
    void level(TreeNode* root,vector<int>&ans){
        if(root==NULL)
        return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>a;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                a.push_back(node->val);
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
            }
            int p=a.size()-1;
            ans.push_back(a[p]);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        level(root,ans);
        return ans;
    }
};